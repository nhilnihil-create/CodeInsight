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
    ll n,k;
    cin >> n >> k;
    if(k%2==0){
        ll a = n/k;
        ll b;
        if(n>=k/2){
            b = (n-k/2)/k + 1;
        }else{
            b = 0;
        }
        cout << (ll)a*a*a + b*b*b << endl;
    }else{
        int a = n/k;
        cout <<(ll) a*a*a << endl;
    }

    return 0;
}