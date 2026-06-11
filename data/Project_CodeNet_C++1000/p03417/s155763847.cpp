#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(), (a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;

    ll ans;

    if (n >= 3 && m >= 3)
        ans = (n - 2) * (m - 2);
    else if (n == 2 || m == 2)
        ans = 0;
    else if (n == 1 || m == 1)
        ans = max(max(n - 2, m - 2), 1ll);

    cout << ans << endl;
}