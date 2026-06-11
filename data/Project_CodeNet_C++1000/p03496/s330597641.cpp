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

        vector<Int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int max_key = -1;
        Int max_val = -1;


        for (int i = 0; i < N; ++i) {
            if (max_val < abs(A[i])) {
                max_val = abs(A[i]);
                max_key = i;
            }
        }

        vector<pair<int, int>> ans;
        auto tapi = [&](int i, int j) {
            ans.emplace_back(i + 1, j + 1);
            A[j] += A[i];
        };

        bool minus = A[max_key] < 0;
        for (int i = 0; i < N; ++i) {
//            ans.emplace_back(max_key + 1, i + 1);
//            A[i] += max_key;
            tapi(max_key, i);
        }


        if (minus) {
            for (int i = N - 1; i > 0; --i) {
                tapi(i, i - 1);
            }
        } else {
            for (int i = 0; i + 1 < N; ++i) {
                tapi(i, i + 1);
            }
        }


        cout << ans.size() << endl;
        for (auto e : ans) {
            cout << e.first << " " << e.second << endl;
        }

        for (int i = 0; i + 1 < N; ++i) {
            if (A[i] > A[i + 1]) {
                cerr << "damedesu" << endl;
            }
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
