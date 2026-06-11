#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int cost[50][50],grid[505][505],n,c;
ll box[3][50],dp[50][3];
vector<pair<int,int> >v[4];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>c;
    for(int i=1; i<=c; i++)
        for(int j=1; j<=c; j++)
            cin>>cost[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>grid[i][j];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int m=(i+j)%3;
            v[m].push_back({i,j});
        }
    }
    int sz0=v[0].size(),sz1=v[1].size(),sz2=v[2].size();
    for(int i=1; i<=c; i++)
    {
        ll cur=0;
        for(int j=0; j<sz0; j++)
        {
            int x=v[0][j].first;
            int y=v[0][j].second;
            if(grid[x][y]!=i)
            {
                cur+=cost[grid[x][y]][i];
            }
        }
        box[0][i]=cur;

        cur=0;
        for(int j=0; j<sz1; j++)
        {
            int x=v[1][j].first;
            int y=v[1][j].second;
            if(grid[x][y]!=i)
            {
                cur+=cost[grid[x][y]][i];
            }
        }
        box[1][i]=cur;
        cur=0;
        for(int j=0; j<sz2; j++)
        {
            int x=v[2][j].first;
            int y=v[2][j].second;
            if(grid[x][y]!=i)
            {
                cur+=cost[grid[x][y]][i];
            }
        }
        box[2][i]=cur;
    }
    ll ans=INT_MAX;
    for(int i=1; i<=c; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(i==j)
                continue;
            for(int k=1; k<=c; k++)
            {
                if(i==k || j==k)
                continue;
            ans=min(ans,box[0][i]+box[1][j]+box[2][k]);
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}
