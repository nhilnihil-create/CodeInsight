#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using bint = boost::multiprecision::cpp_int;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
#define rrepSE(i,s,e) for (int i = (s); i > (e); i--)
#define ssort(v) sort(v.begin(), v.end())
#define gsort(v) sort(v.rbegin(), v.rend())
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
#define DEBUG_PRINT(var) std::cout << #var << " = " << var << "\n";

const int MX = 1001001;

int n, a, b, c;
vector<int> l;

int dfs(int cur, int a0, int b0, int c0) {
    if (cur == n) {
        if (a0 > 0 && b0 > 0 && c0 > 0)
            return abs(a-a0) + abs(b-b0) + abs(c-c0) - 30;
        else
            return MX;
    }
    int ret0 = dfs(cur + 1, a0, b0, c0);
    int ret1 = dfs(cur + 1, a0 + l[cur], b0, c0) + 10;
    int ret2 = dfs(cur + 1, a0, b0 + l[cur], c0) + 10;
    int ret3 = dfs(cur + 1, a0, b0, c0 + l[cur]) + 10;
    return min(min(min(ret0, ret1), ret2), ret3);
}

int main()
{
    cin >> n >> a >> b >> c;
    l = vector<int>(n);
    rep(i,n) cin >> l[i];
    cout << dfs(0, 0, 0, 0) << "\n";
    return 0;
}
