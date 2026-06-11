#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;

int main()
{
    ll n,k; cin >> n >> k;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll sum[n+1]; rep(i,n+1) sum[i] = 0;
    rep(i,n){
        sum[i+1] = a[i]+sum[i];
    }
    map<ll,ll> mp;
    ll ans = 0;
    rep(i,n+1){
        mp[sum[i] % k]++;
    }
    for(auto i:mp){
        ll x = i.second;
        ans += ((x)*(x-1))/2;
    }
    cout << ans << endl;
}
