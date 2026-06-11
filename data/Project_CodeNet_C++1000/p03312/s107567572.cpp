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
typedef pair<ll, ll> P;
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

int n;
ll a[200100];

ll subsum[200100];

P calc_l(int e) {
    ll sum = subsum[e];
    int lb = 0, ub = e;
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if (subsum[mid] <= sum/2) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    if (sum-2*subsum[lb] < 2*subsum[lb+1]-sum) {
        return P(subsum[lb], sum-subsum[lb]);
    } else {
        return P(sum-subsum[lb+1], subsum[lb+1]);
    }
}

P calc_r(int e) {
    ll sum = subsum[n] - subsum[e];
    int lb = e, ub = n;
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if (subsum[mid]-subsum[e] <= sum/2) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    if (sum-2*(subsum[lb]-subsum[e]) < 2*(subsum[lb+1]-subsum[e])-sum) {
        return P(subsum[lb]-subsum[e], subsum[n]-subsum[lb]);
    } else {
        return P(subsum[n]-subsum[lb+1], subsum[lb+1]-subsum[e]);
    }
}

ll solve() {
    for (int i = 1; i <= n; i++) {
        subsum[i] = subsum[i-1] + a[i-1];
    }
    
    ll res = 1e16;
    for (int i = 2; i < n-1; i++) {
        P l = calc_l(i);
        P r = calc_r(i);
        ll p = min(l.first, r.first), q = max(l.second, r.second);
        res = min(res, q-p);
    }
    return res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
