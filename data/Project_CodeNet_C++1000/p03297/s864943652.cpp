#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int t;
ll a[310], b[310], c[310], d[310];

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

void solve() {
    for (int i = 0; i < t; i++) {
        if (a[i] < b[i]) {
            cout << "No" << endl;
        } else if (b[i] > d[i]) {
            cout << "No" << endl;
        } else if (b[i] <= c[i]) {
            cout << "Yes" << endl;
        } else {
            ll r = a[i] % b[i];
            ll g = gcd(b[i], d[i]);
            if (r > c[i]) {
                cout << "No" << endl;
            } else {
                ll x = ((c[i]-r)%g == 0 ? (c[i]-r)/g+1: (c[i] - r + g - 1) / g);
                ll y = ((b[i]-r)%g == 0 ? (b[i]-r)/g-1 : (b[i] - r) / g);
                //cerr << x << " " << y << endl;
                if (x <= y) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            }
        }
    }
}

void input() {
    cin >> t;
    for (int i = 0; i < t; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
