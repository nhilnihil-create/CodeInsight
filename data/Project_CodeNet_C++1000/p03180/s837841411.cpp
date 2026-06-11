#include <bits/stdc++.h>
using namespace std;
#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define all(x) (x).begin(),(x).end()
#define pb push_back
int n;
int dp[1000010],op[1000010];
int a[20][20];
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
    for(int i=1;i<(1<<n);i++)
    {
        for(int x=0;x<n;x++)
        for(int y=x;y<n;y++)
            if(((1<<x)&i)&&((1<<y)&i))
                op[i]+=a[x][y];
        //cout<<i<<" "<<op[i]<<'\n';
    }
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]=max(dp[i],op[i]);
        for(int j=i;j;j=(j-1)&i)
        {
            dp[i]=max(dp[i],dp[j]+op[i^j]);
        }
    }
    cout<<dp[(1<<n)-1];
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("antree.inp","r",stdin);
    //freopen("antree.out","w",stdout);
    //int test;cin>>test;while(test--)
    solve();
    return 0;
}

