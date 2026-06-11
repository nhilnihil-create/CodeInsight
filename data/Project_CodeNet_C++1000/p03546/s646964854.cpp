#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    int h, w;
    cin >> h >> w;

    ll cost[10][10] = {};
    for(int i=0;i<10;++i) {
        for(int j=0;j<10;++j) {
            cin >> cost[i][j];
        }
    }

    for(int k=0;k<10;++k) {
        for(int i=0;i<10;++i) {
            for(int j=0;j<10;++j) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    ll ans = 0;
    int a[h][w];
    for(int i=0;i<h;++i) {
        for(int j=0;j<w;++j) {
            cin >> a[i][j];
            if(a[i][j] == -1) continue;
            ans += cost[a[i][j]][1];
        }
    }

    cout << ans << endl;
}