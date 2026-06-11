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
typedef pair<int, ll> P;
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
int t[100100];
ll d[100100];

ll solve() {
    vector<P> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = make_pair(d[i], t[i]);
    }
    sort(RALL(vec));

    ll dil = 0;
    stack<ll> rem_cand;
    set<int> kinds;
    for (int i = 0; i < k; i++) {
        const P p = vec[i];
        dil += p.first;
        if (kinds.count(p.second) == 0) {
            kinds.insert(p.second);
        } else {
            rem_cand.push(p.first);
        }
    }
    ll k = (ll)kinds.size();
    ll res = dil + k * k;
    for (int i = k; i < n; i++) {
        const P p = vec[i];
        if (kinds.count(p.second) == 0 && !rem_cand.empty()) {
            ll r = rem_cand.top(); rem_cand.pop();
            dil += p.first - r;
            k++;
            kinds.insert(p.second);
            res = max(res, dil + k * k);
        }
    }
    return res;
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> t[i] >> d[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
