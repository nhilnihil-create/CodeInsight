#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int L;
    cin >> L;
    int r = 0;
    while((1 << r + 1) <= L)
        r++;
    int N = r + 1, M = 0;
    using pll = pair<ll, ll>;
    vector<vector<pll>> G(N);

    rep(i, r) {
        G[i].push_back(MP(i + 1, 0));
        G[i].push_back(MP(i + 1, 1 << i));
        M += 2;
    }
    L -= (1 << r);
    ll cost = 1 << r;
    for(int i = r - 1; i >= 0; i--) {
        if(L >= (1 << i)) {
            L -= (1 << i);
            G[i].push_back(MP(N - 1, cost));
            cost += (1 << i);
            M++;
        }
    }
    cout << N << " " << M << endl;
    rep(i, N - 1) {
        for(pll p : G[i]) {
            cout << i + 1 << " " << p.first + 1 << " " << p.second << endl;
        }
    }
    return 0;
}