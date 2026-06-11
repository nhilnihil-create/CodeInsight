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
    int a[n + 1];
    int k;
    cin>>k;
    int dp[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = INT_MAX;
    }
    
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=max(i-k,1ll);j--){
            dp[i] = min(dp[j]+abs(a[i]-a[j]),dp[i]);
        }
    }
    cout<<dp[n];
    return 0;
}