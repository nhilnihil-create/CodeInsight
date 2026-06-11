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
#define MOD 1000000007
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

bool is_prime(ll N)
{
    if (N <= 1)
        return false;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int n = 101000;
    vector<ll> cusum(n, 0);
    for (ll i = 1; i < n; i++)
        cusum[i] = cusum[i - 1] + ((1 & i) && is_prime(i) && is_prime((i + 1) / 2));
    ll q;
    cin >> q;
    vector<int> l(q), r(q);
    rep(i, 0, q) cin >> l[i] >> r[i];
    rep(i, 0, q)
    {
        cout << cusum[r[i]] - cusum[l[i] - 1] << endl;
    }
    return 0;
}