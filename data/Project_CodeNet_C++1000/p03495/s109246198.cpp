#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    ll k, n, num;
    cin >> n >> k;
    deque<ll> a(n, 0);
    rep(i, n)
    {
        cin >> num;
        a[num - 1]++;
    }

    sort(a.begin(), a.end());

    int ans = 0;
    rep(i, n - k)
    {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}