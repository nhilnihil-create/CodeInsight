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
    int r;
    cin >> r;
    string ans = "AGC";
    if (r < 1200)
    {
        ans = "ABC";
    }
    else if (r < 2800)
    {
        ans = "ARC";
    }
    cout << ans << endl;

    return 0;
}