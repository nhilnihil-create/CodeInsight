#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i, n, init) for (ll i = init; i < (n); i++)
#define repd(i, n, init) for (ll i = (n); i >= init; i--)
#define repm(i, m) for (auto i = m.begin(); i != m.end(); i++)

int main()
{
    ll N, ans = 1;
    cin >> N;
    vector<ll> A(N);
    repi(i, N, 0)
    {
        cin >> A[i];
        ans *= 3;
    }
    ll odd = 1;
    repi(i, N, 0)
    {
        if (A.at(i) % 2 == 0)
        {
            odd *= 2;
        }
    }
    cout << ans - odd << endl;
    return 0;
}