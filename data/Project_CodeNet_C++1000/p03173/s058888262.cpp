//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int n;
vi a, sum;
vvi s;
ll dfs(int l, int r) {
    if(s[l][r] != -1) return s[l][r];
    if(r-l == 1) return 0LL;
    ll &res = s[l][r] = LINF;
    for(int i = l+1; i != r; i++) {
        chmin(res, dfs(l, i) + dfs(i, r));
    }
    return res += sum[r]-sum[l];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    sum.resize(n+1);
    s.assign(n, vi(n+1, -1));
    rep(i, n) cin >> a[i];
    rep(i, n) sum[i+1] = sum[i] + a[i];

    cout << dfs(0, n) << endl;
}