#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
    for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
    for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 1e9 + 7LL;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " ";
    }
    if (v.size() > 0) {
        os << v[v.size() - 1] << endl;
    }
    return os;
}

int main() {
    string s;
    cin >> s;
    int sz = s.size();
    if (s[sz - 1] == '1' || s[0] == '0'){
        cout << -1 << endl;
        return 0;
    }
    int sz2 = sz - 1;
    REP(i, sz2 / 2) {
        if (s[i] != s[sz2 - 1 - i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vint vals;
    int val = 0;
    REP(i, sz-1) {
        if (s[i] == '0') {
            ++val;
        } else {
            ++val;
            vals.push_back(val);
            val = 0;
        }
    }
    vals.push_back(1);
    int prev = 1;
    FOR(i, 1, vals.size()){
        int now = prev + vals[i];
        FOR(j, 1, vals[i]) {
            cout << prev + j << " " << prev + vals[i] << endl;
      }
      cout << prev << " " << prev + vals[i] << endl;
      prev = prev + vals[i];
    }
}