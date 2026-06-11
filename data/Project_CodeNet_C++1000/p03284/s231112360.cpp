#include <bits/stdc++.h>
#define rep(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl;

typedef long long ll;
const ll INF = 99999999999999;
const ll MOD = 1000000007;

using namespace std;

int main()
{
    int a, b, ans;
    cin >> a >> b;
    if (a % b == 0)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }
    cout << ans << endl;

    return 0;
}