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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> X(N), Y(N);
    rep(i, 0, N) cin >> X[i] >> Y[i];

    ll max_xy = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (abs(X[i] + Y[i]) % 2 != abs(X[i + 1] + Y[i + 1]) % 2) {
            cout << -1 << endl;
            return 0;
        }
        chmax(max_xy, abs(X[i]) + abs(Y[i]));
    }
    chmax(max_xy, abs(X[N - 1]) + abs(Y[N - 1]));

    vector<ll> v;
    if (abs(X[0] + Y[0]) % 2 == 0) {
        v.push_back(1ll);
    }
    v.push_back(1ll);
    for (int i = 0; v.back() + 1 < max_xy; ++i) {
        v.push_back(v.back() * 2ll);
    }

    reverse(all(v));

    int m = v.size();
    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << v[i];
        if (i < m - 1) cout << " ";
        else cout << endl;
    }
    for (int i = 0; i < N; ++i) {
        ll x = X[i];
        ll y = Y[i];

        string ans;
        for (int j = 0; j < m; ++j) {
            if (abs(x) > abs(y)) {
                if (x > 0) {
                    x -= v[j];
                    ans += 'R';
                } else {
                    x += v[j];
                    ans += 'L';
                }
            } else {
                if (y > 0) {
                    y -= v[j];
                    ans += 'U';
                } else {
                    y += v[j];
                    ans += 'D';
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
