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

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:
    string S;
    int K;
    vector<vector<vector<int>>> dp;

    void input() {
        cin >> S >> K;
        dp.resize(S.size(), vector<vector<int>>(S.size(), vector<int>(K + 1, -1)));
    }

    int rec(int l, int r, int k) {
        if (dp[l][r][k] != -1) return dp[l][r][k];
        if (l == r) return 1;
        if (l + 1 == r) {
            if (k > 0 || S[l] == S[r]) {
                return 2;
            } else {
                return 1;
            }
        }

        int ret = 0;
        if (S[l] == S[r]) {
            chmax(ret, 2 + rec(l + 1, r - 1, k));
        } else {
            ll tmp;
            if (k > 0) {
                tmp = 2 + rec(l + 1, r - 1, k - 1);
                chmax(ret, tmp);
            }
            tmp = rec(l, r - 1, k);
            chmax(ret, tmp);
            tmp = rec(l + 1, r, k);
            chmax(ret, tmp);
        }
        return dp[l][r][k] = ret;
    }

    void solve() {
        input();
        int ans = rec(0, S.size() - 1, K);
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
