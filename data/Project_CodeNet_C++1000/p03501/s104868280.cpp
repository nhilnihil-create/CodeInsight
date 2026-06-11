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

    int n,a,b;
    cin >> n >> a >> b;
    if(n*a<b){
        cout << n*a << endl;
    }

    else{
        cout << b << endl;
    }

    return 0;
}