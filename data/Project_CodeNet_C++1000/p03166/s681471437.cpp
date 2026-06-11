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

const int siz = 1e5 + 10;
vector<int> v[siz];
int dp[siz]={0};
bool vis[siz]={0};

void dfs(int node)
{
    
    vis[node] = true;
    for (int x : v[node])
    {
        if (!vis[x])
        {
            dfs(x);
        }
        
        dp[node] = max(dp[node],1+dp[x]);
    }
}

int32_t main()
{
   // shuru_krte_hai_bina_kisi_bakchodi_ke();
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        
        ans = max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}