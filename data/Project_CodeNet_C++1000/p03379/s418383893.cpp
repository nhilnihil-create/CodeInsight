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
const ll num[4] = {-1, 0, 1, 0};

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> vec(n);
    vector<ll> so(n);

    rep(i, 0, n)
    {
        cin >> vec[i];
        so[i] = vec[i];
    }
    sort(all(so));
    rep(i, 0, n)
    {
        if (vec[i] < so[n / 2])
            cout << so[n / 2] << endl;
        else
            cout << so[n / 2 - 1] << endl;
    }
}
