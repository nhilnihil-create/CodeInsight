#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using pint = pair<int,int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main() {
    int n,k;
    cin>>n>>k;
    vll v(n);
    rep(i,n) cin>>v[i];
    ll ans = -1LL*1e11;
    int mn = min(n, k);

    for(int i=0; i<=mn; i++){
        for(int j=0; j+i<= mn; j++){
            vll a;
            int cnt = k - i - j;
            ll tans=0;
            for(int l = 0; l<i; l++) a.push_back(v[l]);
            for(int l = 0; l< j; l++) a.push_back(v[n-1-l]);
            for(auto at :a) tans += at;
            sort(a.begin(),a.end());
            for(int l = 0; l < cnt&& l<a.size() && a[l]<0; l++) tans -=a[l];
            ans = max(ans, tans);
        }
    }

    cout<<ans<<endl;
    return 0;
    }