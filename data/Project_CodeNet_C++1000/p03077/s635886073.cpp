#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    ll n;
    vector<ll> cost(5);
    cin >> n;
    rep(i, 0, 5) cin >> cost[i];
    cout << 4 + ((n + *min_element(cost.begin(), cost.end()) - 1) / *min_element(cost.begin(), cost.end())) << endl;
}
