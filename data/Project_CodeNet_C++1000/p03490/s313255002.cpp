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
const ll inf = 1e16 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

string s;
int x, y;

bool dp[8010];
bool check(vector<int>& num, int k) {
    int sum = 0;
    for (int v : num) {
        sum += v;
    }
    if ((sum - k) % 2 == 1 || sum < abs(k)) return false;
    k = (sum - k) / 2;
    
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < (int)num.size(); i++) {
        for (int j = k; j >= 0; j--) {
            if (dp[j])
                dp[j+num[i]] = 1;
        }
    }
    return dp[k];
}

bool solve() {
    vector<int> num[2];
    int l = 0, n = (int)s.size();
    while (l < n && s[l] == 'F') {
        x--;
        l++;
    }

    bool p = 0;
    while (l < n) {
        int t = 0;
        while (l + t < n && s[l+t] == 'T') t++;
        if (t % 2 == 1) p = 1 - p;
        l += t;
        int f = 0;
        while (l + f < n && s[l+f] == 'F') f++;
        num[p].push_back(f);
        l += f;
    }
    return check(num[0], x) && check(num[1], y);
}

void input() {
    cin >> s >> x >> y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << (solve() ? "Yes" : "No") << endl;;
}
