/**
*    created: 16.05.2020 08:07:58
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    ll n;
    cin>>n;
    ll ans=0;
    rep(i, sqrt(n) + 1) if (i * i <= n) ans = i*i;
    cout << ans<< endl;
}