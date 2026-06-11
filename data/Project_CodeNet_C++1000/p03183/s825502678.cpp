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
const ll inf = 1e17;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
int w[1010], s[1010];
ll v[1010];

ll dp[20010];

ll solve() {
    vector<P> vec(n);
    for (int i = 0; i < n; i++) vec[i] = make_pair(w[i]+s[i], i);
    sort(ALL(vec));

    for (int i = 1; i < 20010; i++) {
        dp[i] = -inf;
    }

    for (P p : vec) {
        int i = p.second;
        for (int j = s[i]; j >= 0; j--) {
            if (dp[j] < 0) continue;
            dp[j+w[i]] = max(dp[j+w[i]], dp[j]+v[i]);
        }
    }

    ll res = 0;
    for (int i = 1; i < 20010; i++) {
        res = max(res, dp[i]);
    }
    return res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i] >> s[i] >> v[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
