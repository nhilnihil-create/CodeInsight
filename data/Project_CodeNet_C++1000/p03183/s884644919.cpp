#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
const int inf=1e18;
///----------------------------------------------------
vector<vector<int> > dp;
int n;
int SLIM=10005;
struct st
{
    int s,w,v;
};
bool cmp(st x,st y)
{
    return x.w+x.s<y.w+y.s;
}
vector<st> vec;
void init()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i].w>>vec[i].s>>vec[i].v;
    }
    dp.resize(n+1,vector<int>(SLIM,-inf));
    sort(vec.begin(),vec.end(),cmp);
}

void assin(int i,int j,int val)
{
    if(i<0||j<0||j>=SLIM||i>n)
        return ;
    dp[i][j]=max(dp[i][j],val);
}

void solve()
{
    dp[0][0]=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<SLIM;j++)
        {
            if(dp[i][j]<0)
                continue;
            assin(i+1,j,dp[i][j]);
            maxi=max(maxi,dp[i][j]);
            if(j<=vec[i].s)
            {
                assin(i+1,j+vec[i].w,dp[i][j]+vec[i].v);
                maxi=max(maxi,dp[i][j]+vec[i].v);
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<SLIM;j++)
        {
//            if(dp[i][j]!=-inf)
//            cerr<<setw(3)<<dp[i][j]<<" ";
//            else
//                cerr<<setw(3)<<"inf"<<" ";
            maxi=max(maxi,dp[i][j]);
        }
//        cerr<<"\n";
    }
    cout<<maxi;
}
signed main()
{
    init();
    solve();
    return 0;
}

















