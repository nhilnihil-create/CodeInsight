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
typedef pair<string, string> S;
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
string s;

map<pair<P, S>, ll> memo;

ll calc(int l, int r, string pre0, string pre1) {
    const pair<P, S> key = make_pair(make_pair(l, r), make_pair(pre0, pre1));
    if (l >= r) {
        return (ll)(pre0 == pre1);
    } else {
        if (memo.count(key) == 0) {
            ll res = 0;
            for (int i = l; i <= r; i++) {
                for (int j = i-1; j < r; j++) {
                    if ((i == j) ||
                        (l <= j && i < r && s[i] != s[j]))
                        continue;
                    string npre0 = "";
                    string npre1 = "";
                    for (int k = j+1; k < r; k++) npre0 += s[k];
                    for (int k = i-1; k >= l; k--) npre1 += s[k];
                    npre0 += pre0;
                    npre1 += pre1;
                    const int l0 = npre0.size();
                    const int l1 = npre1.size();
                    if (l0 > 0 && l1 > 0 && 
                        ((l0 <= l1 && npre0 != npre1.substr(l1-l0, l0)) ||
                         (l0 > l1 && npre0.substr(l0-l1, l1) != npre1))) {
                             continue;
                    }
                    res += calc(i+1, j, npre0, npre1);
                }
            }
            memo[key] = res;
        }
        return memo[key];
    }
}

ll solve() {
    return calc(0, 2*n, "", "");
}

void input() {
    cin >> n >> s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
