#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
    
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll l(n+1), r(n+1);
    l[n] = 2;
    r[n] = 2;
    for (int i = n-1; i >= 0; --i) {
        ll mn = (l[i+1] + a[i] - 1) / a[i] * a[i];
        ll mx = r[i+1] / a[i] * a[i];
        if (!(mn <= mx)) {
            cout << -1 << endl;
            return 0;
        }
        l[i] = mn;
        r[i] = mx + a[i] - 1;
    }
    cout << l[0] << " " << r[0] << endl;
    // if (a[n-1] != 2) {
    //     cout << -1 << endl;
    //     return 0;
    // }
    // ll pre = 2;
    // for (int i = n-2; i >= 0; --i) {
    //     ll nxt = ((pre + a[i] - 1) / a[i]) * a[i];
    //     if ((nxt / a[i+1]) * a[i+1] != pre) {
    //         cout << -1 << endl;
    //         return 0;
    //     }
    //     pre = nxt;
    // }
    // ll mn = pre;
    
    // pre = 2;
    // for (int i = n-2; i >= 0; --i) {
    //     ll nxt = ((pre + a[i] - 1) / a[i]) * a[i];
    //     while (((nxt + a[i]) / a[i+1]) * a[i+1] == pre) nxt += a[i];
    //     pre = nxt;
    // }
    // ll mx = pre + a[0] - 1;
    // cout << mn << " " << mx << endl;
}