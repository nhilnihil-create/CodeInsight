#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};
constexpr int A_MAX = 200000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        a[i] %= m;
        if(i) a[i] += a[i-1];
        a[i] %= m;
    }

    ll ans = 0LL;
    map<ll, ll> cnt;
    cnt[0] = 1LL;
    for(int i=0;i<n;++i) {
        ans += cnt[a[i]]++;
    }

    cout << ans << endl;
}