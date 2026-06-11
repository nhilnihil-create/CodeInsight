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

string s;

void solve() {
    const int n = (int)s.size();
    if (s[n-1] == '1' || s[0] == '0' || s[n-2] == '0') {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n-1; i++) {
        if (s[i] != s[n-i-2]) {
            cout << -1 << endl;
            return;
        }
    }

    vector<P> res;
    int r = 0, p = 0;
    for (int i = 1; i < n/2; i++) {
        if (s[i] == '1') {
            int d = i+1-r;
            int np = p+d-1;
            res.push_back(make_pair(np, p));
            for (int j = p+1; j < np; j++) {
                res.push_back(make_pair(np, j));
            }
            p = np;
            r = i;
        }
    }

    if (p < n-1) {
        res.push_back(make_pair(p, p+1));
        p++;
        for (int i = p+1; i < n; i++) {
            res.push_back(make_pair(p, i));
        }
    }
    for (P p : res) {
        cout << p.first+1 << " " << p.second+1 << endl;
    }
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
