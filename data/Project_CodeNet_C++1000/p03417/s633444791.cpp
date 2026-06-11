#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;

    if(n==1&&m==1){
        cout << 1;
        return 0;
    }

    if(n==1){
        cout << m-2;
        return 0;
    }
    if(m==1){
        cout << n-2;
        return 0;
    }

    cout << (n-2)*(m-2);
    return 0;
}