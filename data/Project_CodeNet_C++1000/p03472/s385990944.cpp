#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, h;
    cin >> n >> h;

    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int amax = max_element(a.begin(), a.end()) - a.begin();

    vi largeb;
    int cnt = 0;
    rep(i, n) {
        if (a[amax] < b[i]) {
            largeb.pb(b[i]);
            cnt++;
        }
    }
    sort(largeb.rbegin(), largeb.rend());
    vll sm(cnt + 1, 0);
    rep(i, cnt) sm[i+1] = sm[i] + largeb[i];

    int ans = 0;
    if (a[amax] == b[amax]) {
        if (h <= sm[cnt]) {
            ans = lower_bound(sm.begin(), sm.end(), h) - sm.begin();
            cout << ans << endl;
        } else {
            ans += cnt;
            h -= sm[cnt];
            ans += 1;
            h -= b[amax];
            ans += (h + a[amax] - 1) / a[amax];
            cout << ans << endl;
        }
    } else {
        if (h <= sm[cnt]) {
            ans = lower_bound(sm.begin(), sm.end(), h) - sm.begin();
            cout << ans << endl;
        } else {
            ans += cnt;
            h -= sm[cnt];
            ans += (h + a[amax] - 1) / a[amax];
            cout << ans << endl;
        }
    }
}