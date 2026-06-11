/* To Kaise Hain Aaplog*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) (x).begin(), (x).end()

void shuru_krte_hai_bina_kisi_bakchodi_ke()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int32_t main()
{
    //shuru_krte_hai_bina_kisi_bakchodi_ke();
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int dp[n + 1] = {0};
    dp[1] = 0;
    dp[2] = abs(a[1] - a[2]);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout<<dp[n];
    return 0;
}