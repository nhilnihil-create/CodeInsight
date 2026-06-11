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

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i, 0, n) cin >> h[i];
    ll ans = 0;
    bool flag = true;
    if (*max_element(all(h)) == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    while (flag)
    {
        ll start = 0;
        rep(i, 0, n)
        {
            if (h[i] != 0)
            {
                start = i;
                break;
            }
        }
        ll end = n;
        rep(i, start, n)
        {
            if (h[i] == 0)
            {
                end = i;
                break;
            }
        }

        rep(i, start, end)
            h[i]--;
        ++ans;
        if (*max_element(all(h)) == 0)
            flag = false;
    }
    cout << ans << endl;
}
