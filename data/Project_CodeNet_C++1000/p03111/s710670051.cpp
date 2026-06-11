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

deque<int> int2vec(int bina, int n){
    deque<int> ans;
    for (int i = 0; bina>0 ; i++)
    {
        ans.push_front(bina%4);
        bina = bina/4;
    }
    int j = ans.size();
    while (j < n) {
        ans.push_front(0);
        j++;
    }
    return ans;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int ans = MX;
    rep (i, 1<<(2*n)) {
        deque<int> vec = int2vec(i, n);
        int a0 = 0, b0 = 0, c0 = 0;
        int mpa = -10, mpb = -10, mpc = -10;
        rep(i, n) {
            if (vec[i] == 0) {a0 += l[i]; mpa += 10;}
            if (vec[i] == 1) {b0 += l[i]; mpb += 10;}
            if (vec[i] == 2) {c0 += l[i]; mpc += 10;}
        }
        if (a0 == 0 || b0 == 0 || c0 == 0) continue;
        int mp = max(mpa, 0) + max(mpb, 0) + max(mpc, 0) + abs(a - a0) + abs(b - b0) + abs(c - c0);
        chmin(ans, mp);
    }
    cout << ans << "\n";
    return 0;
}
