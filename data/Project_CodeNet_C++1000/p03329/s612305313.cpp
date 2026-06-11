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
    ll n;
    cin >> n;
    vi dp(100008);
    rep(i,6) dp.at(i) = i;
    for(ll i=6; i< 100008; i++){
        ll j=6;
        ll jres = INF;
        while(i-j>=0){
            jres = dp.at(i-j)+1;
            j*=6;
        }
        ll k=9;
        ll kres = INF;
        while(i-k>=0){
            kres = dp.at(i-k)+1;
            k*=9;
        }
        dp.at(i) = min(jres,kres);
        // cerr << "i:" << i << " dp.at(i):" << dp.at(i) << endl;
    }
    cout << dp.at(n) << endl;
}