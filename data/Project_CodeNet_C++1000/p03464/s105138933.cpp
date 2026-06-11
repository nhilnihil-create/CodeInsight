#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;

const int INF = 1 << 30;
const int MOD = 1e9 + 7;

vector<int> memo1;
vector<int> memo2;
vector<vector<int>> g;

void dfs(int v, vector<int>& memo, int d=0,int p=-1){
    memo[v] = d;
    for (int nv: g[v]) {
        if (nv == p) continue;
        dfs(nv, memo, d+1, v);
    }
}

int main() {
    int k; cin >> k;
    vector<int> a(k); rep(i, k) cin >> a[i];
    ll child = 2;
    ll mn = 2;
    ll mx = 2;
    for (int i = k-1; i >= 0; i--) {
        if ((mn + a[i]) % a[i] > 0) mn = (mn / a[i] + 1) * a[i];
        mx = mx / a[i] * a[i] + a[i] - 1;
        if (mn > mx) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << mn << " " << mx << endl;

    return 0;
}