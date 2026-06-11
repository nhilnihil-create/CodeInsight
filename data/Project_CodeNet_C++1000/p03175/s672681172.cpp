#include<bits/stdc++.h>
#define sf1(n) scanf("%d",&n)
#define sf2(n,q) scanf("%d %d",&n,&q)
#define f first
#define ss second
#define pb push_back
#define lli long long
#define mem(ar,false) memset(ar,false,sizeof(ar))
#define mpr make_pair
#define endl "\n"
#define mod 1000000007
#define inf 9000000000000000000LL
using namespace std;

int ar[22][22];
lli dp[2097155];
vector<int>v[200005];
pair<lli,lli> dfs(int u,int par)
{
    lli white = 1;
    lli black = 0;
    for(int it : v[u])
    {
        if(it != par)
        {
            pair<lli,lli> p = dfs(it,u);  // p.first is the number of ways to color the subtree black,p.ss number of ways to color the subtree white

            black = (white*p.f) + black*(p.f+p.ss);
            black %= mod;
            white *= p.ss;
            white %= mod;
        }
    }

    return mpr(white,(white+black)%mod);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }

    pair<lli,lli>ans = dfs(1,-1);

    cout << (ans.f+ans.ss)%mod << endl;
    return 0;

}

