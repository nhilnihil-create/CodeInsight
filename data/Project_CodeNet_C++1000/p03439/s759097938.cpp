#include <bits/stdc++.h>

#define TYPE(c)   remove_reference_t<decltype(c)>
#define REP(i, n) for(TYPE(n) i = 0; i < n; i++)
#define FOR(v, c) for(TYPE(c.begin()) v = c.begin(); v != c.end(); v++)
#define ALL(c)    c.begin(), c.end()
#define SORT(c)   sort(ALL(c))
#define RSORT(c)  sort(ALL(c), greater<TYPE(c)::value_type>())
#define UNIQUE(c) c.erase(unique(ALL(c)), c.end())

using namespace std;
using ll = long long;

constexpr int MOD  = (int)1e9 + 7;
constexpr int INF  = (int)1e9 + 1;
constexpr ll  LINF = (ll)1e18 + 1;
template<typename T> constexpr bool chmax(T& a, const T& b)
{ if(a < b) { a = b; return true; } else { return false; } }
template<typename T> constexpr bool chmin(T& a, const T& b)
{ if(b < a) { a = b; return true; } else { return false; } }
template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T>& p)
{ return os << "(" << p.first << "," << p.second << ")"; }
ostream& operator<<(ostream &os, const string& s)
{ FOR(v, s) os << *v; return os; }
template<typename T> auto operator<<(ostream& os, const T& t)
    -> typename conditional<true, ostream&, decltype(*t.begin())>::type
{ os << "["; FOR(v, t) { if(v != t.begin()) os << ","; os << *v; } os << "]"; return os; }

int main() {
    int N;
    std::cin >> N;

    vector<string> table(N);
    auto get = [&](auto index) -> bool {
                   std::cout << index << "\n";
                   cout.flush();
                   std::cin >> table[index];
                   return (table[index] == "Vacant") ? true : false;
               };

    auto r = 0;
    auto l = N - 1;
    if(!get(r) && !get(l)) {
        while(true) {
            auto med = (r + l) / 2;
            if(get(med)) {
                break;
            }
            else if(table[r] == table[med] && abs(r - med) % 2 == 1) {
                l = med;
            }
            else if(table[r] != table[med] && abs(r - med) % 2 == 0) {
                l = med;
            }
            else {
                r = med;
            }
        }
    }

    return 0;
}
