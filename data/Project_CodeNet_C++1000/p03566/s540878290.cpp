#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
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

const int INF = 1001001001;

double f(int v, int s, int e, double t) {
    if (t < s) return v + (s - t);
    else if (s <= t && t <= e) return v;
    else return v + (t - e);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi t(n), v(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> v[i];
    vi smt(n+1, 0);
    rep(i, n) smt[i+1] = smt[i] + t[i];
    vector<double> ans(2*smt[n]+1, INF);
    rep(i, sz(ans)) {
        double t = i / 2.0;
        chmin(ans[i], t);
        rep(j, n) {
            chmin(ans[i], f(v[j], smt[j], smt[j+1], t));
        }
        chmin(ans[i], smt[n] - t);
    }
    double dist = 0;
    rep(i, sz(ans) - 1) {
        dist += (ans[i] + ans[i+1]) / 4.0;
    }
    cout << fixed << setprecision(15) << dist << endl;
    
}