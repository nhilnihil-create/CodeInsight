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

int n;
int d[55];

int solve() {
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[d[i]]++;
        if (d[i] == 0 || (d[i] == 12 && m[d[i]] >= 2) || m[d[i]] >= 3) {
            return 0;
        }
    }

    vector<int> s;
    vector<int> b;
    b.push_back(0);
    b.push_back(24);
    for (auto v : m) {
        if (v.first != 12 && v.second == 1) {
            s.push_back(v.first);
        } else if (v.first == 12) {
            b.push_back(12);
        } else {
            b.push_back(v.first);
            b.push_back(24-v.first);
        }
    }
    const int l = (int)s.size();
    int res = 0;
    for (int i = 0; i < (1<<l); i++) {
        vector<int> c = b;
        for (int j = 0; j < l; j++) {
            if ((i>>j)&1) {
                c.push_back(s[j]);
            } else {
                c.push_back(24-s[j]);
            }
        }
        sort(ALL(c));
        int g = inf;
        for (int j = 0; j < (int)c.size()-1; j++) {
            g = min(g, c[j+1]-c[j]);
        }
        res = max(res, g);
    }
    return res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
