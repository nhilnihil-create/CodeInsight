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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vec(n);
    rep(i, 0, n) cin >> vec[i].first >> vec[i].second;
    sort(all(vec));
    ll ans = 0;
    ll kosuu = 0;
    rep(i, 0, n)
    {
        ll nanko = min(m - kosuu, vec[i].second);
        kosuu += nanko;
        ans += vec[i].first * nanko;
        if (kosuu >= m)
            break;
    }
    cout << ans << endl;
}
