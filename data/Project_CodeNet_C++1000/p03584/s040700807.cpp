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

int n, k;
int a[100100];
ll b[100100];

ll calc(int m) {
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        if ((m & a[i]) == a[i])
            ret += b[i];
    }
    return ret;
}

ll solve() {
    ll res = calc(k);
    for (int i = 0; i < 30; i++) {
        if ((k>>i)&1) {
            res = max(res, calc((k ^ (1<<i)) | ((1<<i)-1)));
        }
    }
    return res;
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
