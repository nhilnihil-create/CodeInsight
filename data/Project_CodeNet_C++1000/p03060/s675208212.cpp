#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<int> v(n), c(n);
    rep(i, 0, n) cin >> v[i];
    rep(i, 0, n) cin >> c[i];
    int ans = 0;
    rep(i, 0, 1 << n)
    {
        vector<int> temp;
        int diff = 0;
        rep(j, 0, n) if (i >> j & 1) temp.push_back(j);
        for (auto j : temp)
        {
            diff += v[j] - c[j];
        }
        ans = max(ans, diff);
    }
    cout << ans << endl;
}
