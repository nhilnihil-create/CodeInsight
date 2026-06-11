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

int n;

bool ng[30010];
bool check(int j, int p) {
    for (int i = 2; i < p; i++) {
        if (j % i == 0)
            return false;
    }
    return true;
}

vector<int> calc(int p) {
    memset(ng, false, sizeof(ng));
    for (int i = p; i < 30000; i++) {
        ng[i] = check(i, p);
    }

    int d = (p == 11 ? 2*3*5*7 : 2*3*5*7*11);
    
    vector<int> res;
    int sum = 0;
    for (int i = 2; i < 30000; i++) {
        if (ng[i]) continue;
        res.push_back(i);
        sum += i;
        if ((int)res.size() == n-1) {
            i++;
            while (i <= 30000) {
                if (!ng[i] && (sum+i) % d == 0) {
                    res.push_back(i);
                    break;
                }
                i++;
            }
            break;
        }
    }
    return res;
}

void solve() {
    vector<int> res = calc(11);
    if ((int)res.size() < n) res = calc(13);

    for (int v : res) {
        cout << v << " ";
    }
    cout << endl;
}

void input() {
    cin >> n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
