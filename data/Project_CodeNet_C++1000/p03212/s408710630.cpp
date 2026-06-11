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

ll dig2num(deque<ll> digs) {
    ll ret = digs[0];
    repSE(i,1,digs.size()) {
        ret = ret * 10 + digs[i];
    }
    return ret;
}

bool check753(deque<ll> arr) {
    bool has3 = false, has5 = false, has7 = false;
    for (auto ele : arr) {
        if (ele == 3) has3 = true;
        else if (ele == 5) has5 = true;
        else if (ele == 7) has7 = true;
    }
    return has3 && has5 && has7;
}

int main()
{
    ll n;
    cin >> n;
    int ans = 0;
    deque<ll> a = {3,5,7};
    //
    auto upddig = [&](int n) {
        bool carry = false;
        if(a[n] == 3) a[n] = 5;
        else if(a[n] == 5) a[n] = 7;
        else if(a[n] == 7) {a[n] = 3; carry = true;}
        return carry;
    };
    //
    auto update = [&]() {
        bool carry = upddig(a.size() - 1);
        int i = a.size() - 1;
        while (carry && i > 0) {
            i--;
            carry = upddig(i);
        }
        if (carry) a.push_front(3);
    };
    //
    while (dig2num(a) <= n) {
        ans ++;
        update();
        while (!check753(a)) {
            update();
        }
    }
    cout << ans << "\n";
    return 0;
}
