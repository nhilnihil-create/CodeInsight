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

int l;

vector<T> calc(const int c, int L) {
    int i = 1;
    int p = 1;
    vector<T> vec;
    while (p*c <= L) {
        for (int j = 0; j < c; j++) {
            vec.push_back(make_tuple(i, i+1, p*j));
        }
        i++;
        p *= c;
    }

    int N = 20;
    int s = 0;
    i = 1;
    p = 1;
    while (L > 0) {
        int r = L % c;
        for (int k = 0; k < r; k++) {
            vec.push_back(make_tuple(i, N, s));
            s += p;
        }
        i++;
        p *= c;
        L /= c;
    }
    return vec;
}

void solve() {
    for (int c = 3; c < 10; c++) {
        vector<T> ret = calc(c, l);
        if ((int)ret.size() <= 60) {
            cout << 20 << " " << (int)ret.size() << endl;
            for (T t : ret) {
                cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
            }
            return;
        }
    }
}

void input() {
    cin >> l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
