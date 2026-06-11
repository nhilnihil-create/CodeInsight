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

        vector<Int> rui = A;
        for (int i = 0; i + 1 < N; ++i) {
            rui[i + 1] += rui[i];
        }

        auto getPQ = [&](int k) {
            Int sum = rui[k - 1];
            Int mid = sum / 2;
            int cent = lower_bound(all(rui), mid) - rui.begin();

            Int ret = INFl;
            Int P = -1, Q = -1;
            for (int i = cent - 3; i < cent + 3; ++i) {
                if (i >= 0 && i < k) {
                    Int tP = rui[i];
                    Int tQ = sum - rui[i];
                    Int tmp = abs(tP - tQ);
                    if (ret > tmp) {
                        ret = tmp;
                        P = tP;
                        Q = tQ;
                    }
                }
            }

            return make_pair(P, Q);
        };

        auto getRS = [&](int k) {
            Int sum = rui[N - 1] - rui[k - 1];
            Int mid = sum / 2;
            Int hojo = rui[k - 1];
            int cent = lower_bound(all(rui), mid + hojo) - rui.begin();

            Int ret = INFl;
            Int P = -1, Q = -1;
            for (int i = cent - 3; i < cent + 3; ++i) {
                if (i >= k && i < N) {
                    Int tP = rui[i] - hojo;
                    Int tQ = sum - tP;
                    Int tmp = abs(tP - tQ);
                    if (ret > tmp) {
                        ret = tmp;
                        P = tP;
                        Q = tQ;
                    }
                }
            }

            return make_pair(P, Q);
        };

        Int ans = INFl;
        for (int i = 2; i + 2 <= N; ++i) {
            // left
            auto PQ = getPQ(i);
            Int P = PQ.first;
            Int Q = PQ.second;

            // right
            auto RS = getRS(i);
            Int R = RS.first;
            Int S = RS.second;

            vector<Int> arr{P, Q, R, S};
            sort(all(arr));

            Int min_v = arr[0];
            Int max_v = arr[3];
            Int tmp = max_v - min_v;
            chmin(ans, tmp);
        }

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
