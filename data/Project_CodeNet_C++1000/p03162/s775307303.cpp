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
   // shuru_krte_hai_bina_kisi_bakchodi_ke();
    int n;
    cin >> n;
    int a, b, c;
    
    int dp[n + 1][3] = {0};
    cin >> a >> b >> c;
    dp[1][0] = a;
    dp[1][1] = b;
    dp[1][2] = c;
    for (int i = 2; i <= n; i++)
    {
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + c;
    }
    cout << max(dp[n][1], max(dp[n][2], dp[n][0]));

    return 0;
}