#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P; 
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a+2), t(b+2);
    rep(i, a) cin >> s[i+1];
    rep(i, b) cin >> t[i+1];
    s[0] = -INF, t[0] = -INF;
    s[a+1] = INF, t[b+1] = INF;

    rep(i, q){
        ll x;
        cin >> x;
        auto siter = lower_bound(s.begin(), s.end(), x);
        auto titer = lower_bound(t.begin(), t.end(), x);
        ll s1 = s[siter - s.begin()], s2 = s[siter - s.begin() - 1];
        ll t1 = t[titer - t.begin()], t2 = t[titer - t.begin() - 1];

        ll ans = INF;

        // if (s1==s2 and t1==t2){
        //     if ((s1>x and t1>x) or (s1<=x and t1<=x)){
        //         chmin(ans, max(abs(s1-x), abs(t1-x)));
        //     }else{
        //         chmin(ans, abs(s1-t1) + min(abs(s1-x), abs(t1-x)));
        //     }
        // }else if (s1==s2) {
        //     if (s1>x){
        //         chmin(ans, max(s1-x, t1-x));
        //         chmin(ans, s1-t2 + min(s1-x, x-t2));
        //     }else{
        //         chmin(ans, max(abs(s1-x), abs(t2-x)));
        //         chmin(ans, t1-s1 + min(abs(s1-x), abs(t1-x)));
        //     }
        // }else if (t1==t2){
        //     if (t1>x){
        //         chmin(ans, max(s1-x, t1-x));
        //         chmin(ans, t1-s2 + min(t1-x, x-s2));
        //     }else{
        //         chmin(ans, max(abs(t1-x), abs(s2-x)));
        //         chmin(ans, s1-t1 + min(abs(s1-x), abs(t1-x)));
        //     }
        // }else{
        //     chmin(ans, max(s1-x, t1-x));
        //     chmin(ans, max(abs(s2-x), abs(t2-x)));
        //     chmin(ans, s1-t2 + min(abs(s1-x), abs(x-t2)));
        //     chmin(ans, t1-s2 + min(abs(t1-x), abs(s2-x)));
        // }

        chmin(ans, max(s1-x, t1-x));
        chmin(ans, max(abs(s2-x), abs(t2-x)));
        chmin(ans, s1-t2 + min(abs(s1-x), abs(x-t2)));
        chmin(ans, t1-s2 + min(abs(t1-x), abs(s2-x)));
        cout << ans << endl;
    }
    return 0;
}