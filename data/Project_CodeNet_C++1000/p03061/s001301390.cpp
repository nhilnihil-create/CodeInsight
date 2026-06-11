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
    vector<ll> v(n), a(n + 1), b(n + 1);
    rep(i, 0, n) cin >> v[i];
    a[0] = 0, b[n] = 0;
    a[1] = v[0], b[n - 1] = v[n - 1];
    rep(i, 0, n - 1)
    {
        a[i + 2] = __gcd(a[i + 1], v[i + 1]);
        b[n - 2 - i] = __gcd(b[n - 1 - i], v[n - 1 - i - 1]);
    }
    // rep(i, 0, n + 1) cout << a[i] << " ";
    // cout << endl;
    // rep(i, 0, n + 1) cout << b[i] << " ";
    ll ans = 0;
    rep(i, 0, n + 1)
    {
        if (a[i] == 0)
            ans = max(ans, b[i + 1]);
        else if (b[i + 1] == 0)
            ans = max(ans, a[i]);
        else
            ans = max(ans, __gcd(a[i], b[i + 1]));
    }
    cout << ans << endl;
}
