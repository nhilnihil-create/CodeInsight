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
using vi = vector<int>;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, rs;
    cin >> n >> s;
    rs = s.substr(n);
    reverse(all(rs));

    vector<pair<string, string> > ves(1<<n);
    rep(i, 1<<n) {
        string x, y;
        rep(j, n) {
            if(i>>j&1) x += s[j];
            else y += s[j];
        }
        ves[i] = make_pair(x, y);
    }
    sort(all(ves));

    ll ans = 0;
    rep(i, 1<<n) {
        string x, y;
        rep(j, n) {
            if(i>>j&1) x += rs[j];
            else y += rs[j];
        }
        auto pitr = equal_range(all(ves), make_pair(x, y));
        ans += pitr.second - pitr.first;
    }

    cout << ans << endl;
}