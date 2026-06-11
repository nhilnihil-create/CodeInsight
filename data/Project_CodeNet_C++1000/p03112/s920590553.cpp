#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll a, b, q; cin >> a >> b >> q;
    vi s(a+2, (1LL<<60)), t(b+2, (1LL<<60));
    repf(i, a) cin >> s[i]; s[0] *= -1;
    repf(i, b) cin >> t[i]; t[0] *= -1;

    rep(cnt, q){
        ll x; cin >> x;

        // xを始点に東西で最短距離の神社と寺を探す。
        ll EsIdx = lower_bound(all(s), x)-s.begin();
        ll EtIdx = lower_bound(all(t), x)-t.begin();
        ll WsIdx = (s[EsIdx] == x ? EsIdx : EsIdx-1);
        ll WtIdx = (t[EtIdx] == x ? EtIdx : EtIdx-1);

        // (E,E), (E,W), (W,E), (W,W)の4パターンを試して最小値を出力
        ll ans = INFLL;
        
        // (E,E)
        if(s[EsIdx] != (1LL<<60) && t[EtIdx] != (1LL<<60)) chmin(ans, abs(max(s[EsIdx], t[EtIdx])-x));

        // (W,W)
        if(s[WsIdx] != -(1LL<<60) && t[WtIdx] != -(1LL<<60)) chmin(ans, abs(min(s[WsIdx], t[WtIdx])-x));

        // (E,W)(W,E)
        if(s[EsIdx] != (1LL<<60) && t[WtIdx] != -(1LL<<60)) chmin(ans, min(abs(x-s[EsIdx]), abs(x-t[WtIdx]))*2+max(abs(x-s[EsIdx]), abs(x-t[WtIdx])));
        if(s[WsIdx] != -(1LL<<60) && t[EtIdx] != (1LL<<60)) chmin(ans, min(abs(x-s[WsIdx]), abs(x-t[EtIdx]))*2+max(abs(x-s[WsIdx]), abs(x-t[EtIdx])));
        cout << ans << endl;
    }
}