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
typedef pair<ll, int> P;
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

int n;
ll a[200100], b[200100];

ll solve() {
    ll res = 0;
    vector<ll> c(n);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < n; j++) {
            c[j] = b[j] & ((1LL<<(i+1))-1);
        }
        sort(ALL(c));

        ll cnt = 0;
        for (int j = 0; j < n; j++) {
            ll d = a[j] & ((1LL<<(i+1))-1);
            cnt += (int)(lower_bound(ALL(c), (1LL<<(i+1))-d) - lower_bound(ALL(c), (1LL<<i)-d));
            cnt += (int)(lower_bound(ALL(c), (1LL<<(i+2))-d) - lower_bound(ALL(c), (3LL<<i)-d));
        }
        if (cnt % 2 == 1) {
            res |= (1LL<<i);
        }
    }
    return res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
