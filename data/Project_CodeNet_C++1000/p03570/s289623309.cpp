#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>
#include <cassert>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Solve {
public:
    void solve() {
        string S;
        cin >> S;

        Int sum = 0;
        Int N = S.size();
        vector<Int> dp(N + 1, INFl);
        map<Int, Int> mp;
        dp[0] = 0;
        mp[0] = 0;
        for (int i = 0; i < N; ++i) {
            sum ^= (1ll << (S[i] - 'a'));
            chmin(dp[i + 1], dp[i] + 1);
            if (mp.count(sum)) {
                chmin(dp[i + 1], mp[sum]);
            }

            for (int j = 0; j < 26; ++j) {
                Int tmp = sum ^(1 << j);
                if (mp.count(tmp)) {
                    Int val = mp[tmp] + 1;
                    chmin(dp[i + 1], val);
                }
            }

            mp[sum] = dp[i + 1];
        }
        Int ans = max<Int>(dp[N], 1);
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
