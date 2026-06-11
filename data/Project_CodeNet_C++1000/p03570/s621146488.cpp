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
int dp[1<<26];

int solve() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    const int n = (int)s.size();
    int b = 0;
    int ret;
    for (int i = 1; i <= n; i++) {
        b ^= (1<<(s[i-1]-'a'));
        int res = inf;
        for (int j = 0; j <= 25; j++) {
            int c = b ^ (1<<j);
            if (dp[c] >= 0) {
                res = min(res, dp[c]+1);
            }
        }
        if (dp[b] >= 0) {
            res = min(res, dp[b]+1);
        }
        dp[b] = min((dp[b]<0?inf:dp[b]), res);
        ret = res;
    }
    
    return ret;
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
