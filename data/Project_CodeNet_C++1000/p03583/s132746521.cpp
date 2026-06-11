#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main() {
    ll N;
    cin >> N;
    for(ll n = 1; n <= 3500; n++) {
        for(ll h = 1; h <= 3500; h++) {
            if((4 * h * n - N * h - N * n) != 0 &&
               (N * n * h) % (4 * h * n - N * h - N * n) == 0) {
                ll w = (N * n * h) / (4 * h * n - N * h - N * n);
                if(w <= 0)
                    continue;
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
    return 0;
}