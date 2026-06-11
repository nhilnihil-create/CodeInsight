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

string s;
int k;

int dp[310][310][310];

int calc(int l, int r, int x) {
    if (l == r) return 1;
    if (l > r) return 0;
    if (dp[l][r][x] < 0) {
        int res = 0;
        if (s[l] == s[r]) {
            res = calc(l+1, r-1, x) + 2;
        } else if (x > 0) {
            res = calc(l+1, r-1, x-1) + 2;
        }
        res = max(res, calc(l+1, r, x));
        res = max(res, calc(l, r-1, x));
        
        dp[l][r][x] = res;
    }
    return dp[l][r][x];
}

int solve() {
    memset(dp, -1, sizeof(dp));
    return calc(0, (int)s.size()-1, k);
}

void input() {
    cin >> s >> k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
