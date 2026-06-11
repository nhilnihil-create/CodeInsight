#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    rep (i, a) cin >> s[i];
    rep (i, b) cin >> t[i];
    rep (i, q) cin >> x[i];

   
    rep (i, q) {
        vector<int> useSIdx, useTIdx;
        int tmp1;
        tmp1 = lower_bound(rng(s), x[i]) - s.begin();
        if (tmp1 == a) {
            useSIdx.pb(tmp1 - 1);
        }
        else if (tmp1 == 0) {
            useSIdx.pb(tmp1);
        }
        else {
            useSIdx.pb(tmp1);
            useSIdx.pb(tmp1 - 1);
        }
        tmp1 = lower_bound(rng(t), x[i]) - t.begin();
        if (tmp1 == b) {
            useTIdx.pb(tmp1 - 1);
        }
        else if (tmp1 == 0) {
            useTIdx.pb(tmp1);
        }
        else {
            useTIdx.pb(tmp1);
            useTIdx.pb(tmp1 - 1);
        }

        ll ans = 1000000000000LL;

        rep (p1, useSIdx.size()) rep (p2, useTIdx.size()) {
            ll dist = min(abs(x[i] - s[useSIdx[p1]]), abs(x[i] - t[useTIdx[p2]])) + abs(t[useTIdx[p2]] - s[useSIdx[p1]]);
            chmin(ans, dist);
        }

        cout << ans << endl;
    }   
    
   

    return 0;
}