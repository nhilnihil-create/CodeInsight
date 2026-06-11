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
    Int N, Q;
    string s;
    vector<char> t, d;

    void init() {
        cin >> N >> Q;
        cin >> s;
        t.resize(Q);
        d.resize(Q);
        for (int i = 0; i < Q; ++i) {
            cin >> t[i] >> d[i];
        }
    }

    bool ldie(int x) {
        int y = x;
        for (int i = 0; i < Q; ++i) {
            if (s[y] == t[i]) {
                if (d[i] == 'L') y--;
                else y++;
            }
            if (y < 0) return true;
            if (y >= N) return false;
        }

        return false;
    }

    bool rdie(int x) {
        int y = x;
        for (int i = 0; i < Q; ++i) {
            if (s[y] == t[i]) {
                if (d[i] == 'L') y--;
                else y++;
            }
            if (y < 0) return false;
            if (y >= N) return true;
        }

        return false;
    }

    int compute_ldie() {
        int ok = -1, ng = N + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
//            if (mid == -1) {
//                return -1;
//            }
            if (ldie(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }

    int compute_rdie() {
        int ok = N + 1, ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (rdie(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }

    void solve() {
        int l = compute_ldie();
        int r = compute_rdie();
        if (l + 1 < r - 1) {
            int ans = r - 1 - (l + 1) + 1;
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }

    }
};

struct Fool {
    Int N, Q;
    string s;
    vector<char> t, d;

    void init() {
        cin >> N >> Q;
        cin >> s;
        t.resize(Q);
        d.resize(Q);
        for (int i = 0; i < Q; ++i) {
            cin >> t[i] >> d[i];
        }
    }

    void solve() {
        vector<int> uku(N, 1);
        for (int i = 0; i < Q; ++i) {
            if (d[i] == 'R') {
                for (int j = N - 1; j >= 0; --j) {
                    if (s[j] == t[i]) {
                        if (j + 1 < N) {
                            uku[j + 1] += uku[j];
                        }
                        uku[j] = 0;
                    }
                }
            } else {
                for (int j = 0; j < N; ++j) {
                    if (s[j] == t[i]) {
                        if (j - 1 >= 0) {
                            uku[j - 1] += uku[j];
                        }
                        uku[j] = 0;
                    }
                }
            }
        }
        int ans = 0;
        for (auto e : uku) {
            ans += e;
        }
        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve solve;
//    Fool solve;
    solve.init();
    solve.solve();


    return 0;
}
