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
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:
    void solve() {
        Int N;
        cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; ++i) cin >> S[i];
        vector<vector<char>> vvc(2 * N, vector<char>(2 * N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                vvc[i][j] = vvc[i + N][j] = vvc[i][j + N] = vvc[i + N][j + N] = S[i][j];
            }
        }

        Int cnt = 0;
//        for (int i = N; i < 2 * N; ++i) {
//            int sh = 0;
//            int sw = i;
//            string s;
//            for (int j = 0; j < N; ++j) {
//                int h = sh + j;
//                int w = sw - j;
//                s += vvc[h][w];
//            }
//            string t = s;
//            reverse(all(s));
//            if (s == t) cnt++;
//        }
        for (int A = 0; A < N; ++A) {
            bool ok = true;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (vvc[i + A][j] != vvc[j + A][i]) {
                        ok = false;
                    }
                }
            }
            if (ok)cnt++;
        }
        Int ans = cnt * N;
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
