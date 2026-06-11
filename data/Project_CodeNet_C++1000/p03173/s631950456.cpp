#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

//https://atcoder.jp/contests/dp/tasks
int n;
ll MX = 1e18;
vector<vector<P>> dp;
vector<ll> a(n);

P rec(int l = 0,int r = n){
    if(r-l==1) return make_pair(0,a[l]);
    P &ret = dp[l][r];
    if(ret.first != MX) return ret;

    for(int i = l+1;i<r;i++){
        P L = rec(l,i);
        P R = rec(i,r);
        ll sum = L.second + R.second;
        ll cost = L.first + R.first + sum;
        ret = min(ret,make_pair(cost,sum));
    }

    return ret;
}

int main(){
    cin >> n;
    a.assign(n,0);
    rep(i,n) cin >> a[i];
    dp.assign(n+2,vector<P>(n+2,make_pair(MX,MX)));

    ll ans = rec(0,n).first;
    cout << ans << endl;

    
}