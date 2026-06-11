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
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
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

int k;
ll s[150];

void solve() {
    for (int i = 1; i < 150; i++) {
        int v = i;
        while (v > 0) {
            s[i] += v % 10;
            v /= 10;
        }
    }
    
    vector<P> cand;
    ll q = 0;
    ll sq = 0;
    ll t = 1;
    while (q < 1e16) {
        for (ll i = 1; i < 150; i++) {
            ll v = i * t + q;
            cand.push_back(make_pair(v, s[i]+sq));
        }
        q = 10 * q + 9;
        sq += 9;
        t *= 10;
    }
    sort(ALL(cand));
    UNIQ(cand);

    const int sz = (int)cand.size();
    vector<ll> res;
    for (int i = 0; i < sz; i++) {
        bool f = true;
        for (int j = i+1; j < sz; j++) {
            if ((ld)cand[i].first/cand[i].second > (ld)cand[j].first/cand[j].second) {
                f = false;
                break;
            }
        }
        if (f) {
            res.push_back(cand[i].first);
        }
    }

    for (int i = 0; i < k; i++) {
        cout << res[i] << endl;
    }
}

void input() {
    cin >> k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
