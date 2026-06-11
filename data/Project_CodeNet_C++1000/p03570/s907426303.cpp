#include <iostream>
#include <deque>
#include <random>
#include <bitset>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i, m, n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(x) begin(x), end(x)
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

constexpr int inf = 1e9+7;
int main() {
    string s; cin >> s;
    int n = s.length();
    vector<int> acc(n + 1);
    repeat (i, n) {
        acc[i + 1] = acc[i] ^ (1 << (s[i] - 'a'));
    }
    unordered_map<int, vector<int> > f;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    repeat (r, n) {
        f[acc[r]].push_back(r);
        repeat (c, 27) {
            int k = acc[r + 1] ^ (c == 26 ? 0 : (1 << c));
            if (f.count(k)) {
                auto & ls = f[k];
                repeat (i, min<int>(ls.size(), 300)) {
                    int l = ls[i];
                    setmin(dp[r + 1], dp[l] + 1);
                }
                if (ls.size() > 300) {
                    repeat_from (i, ls.size() - 300, ls.size()) {
                        int l = ls[i];
                        setmin(dp[r + 1], dp[l] + 1);
                    }
                }
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
