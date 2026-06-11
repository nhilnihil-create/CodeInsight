#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n,m;
    cin >> n >> m;
    vi a(n);
    rep(i,n) cin >> a.at(i);
    vi csum(n+1);
    csum.at(0) = 0;
    for(ll i=1; i<n+1; i++) csum.at(i) = csum.at(i-1) + a.at(i-1);
    for(ll i=1; i<n+1; i++) csum.at(i) %= m;
    map<ll,ll> mp;
    for(ll i=1; i<n+1; i++){
        if(mp.count(csum.at(i))){
            mp.at(csum.at(i))++;
        }else{
            mp[csum.at(i)] = 1;
        }
    }
    ll res = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cerr << "key:" << it->first << " value:" << it->second << endl;
        ll count = it->second;
        res += (count*(count-1))/2;
    }
    if(mp.count(0)) res += mp.at(0);
    cout << res << endl;
}
