#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> IntegerToVector(ll bit, ll N) {
    vector<ll> S;
    for (ll i = 0; i < N; ++i) {
        if (bit & (1 << i)) S.push_back(1);
        else S.push_back(0);
    }
    return S;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > s;
    rep1(i, m){
        ll k;
        cin >> k;
        vector<ll> res;
        rep1(j, k){
            ll _s;
            cin >> _s;
            _s--;
            res.push_back(_s);
        }
        s.push_back(res);
    }
    vector<ll> p(m);
    rep1(i, m) cin >> p[i];
    ll ans = 0;
    for (ll bit = 0; bit < (1<<n); ++bit) {
        vector<ll> S = IntegerToVector(bit, n);
        ll res = 0;
        rep1(i, m){
            ll sum = 0;
            for (ll x: s[i]) sum += S[x];
            if (sum%2 == p[i]) res++;
        }
        if (res==m) ans++;
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}