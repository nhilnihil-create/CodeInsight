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

int n, k, q;
int a[2010];

int solve() {
    vector<int> vec;
    vec.push_back(0);
    for (int i = 0; i < n; i++) vec.push_back(a[i]);
    sort(ALL(vec));
    UNIQ(vec);
    int res = inf;
    for (int th : vec) {
        vector<int> cand;
        int idx = 0;
        while (idx < n) {
            int c = 0;
            vector<int> seg;
            while (idx+c<n && a[idx+c] > th) {
                seg.push_back(a[idx+c]);
                c++;
            }
            sort(ALL(seg));
            for (int i = 0; i <= (int)seg.size()-k; i++) {
                cand.push_back(seg[i]);
            }
            idx += c;
            while (idx < n && a[idx] <= th) idx++;
        }
        if ((int)cand.size() < q) break;
        sort(ALL(cand));
        res = min(res, cand[q-1] - cand[0]);
    }
    return res;
}

void input() {
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
