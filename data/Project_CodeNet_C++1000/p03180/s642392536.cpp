#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int maxn=20;
const int maxpos=65540;
int my_popcount[maxpos];
ll a[maxn][maxn],val[maxpos],maxx[maxpos];
vector<int> tmp,useful[maxn];
void fl()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}
int main()
{
//    fl();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
    for(int i=0;i<(1<<n);i++)
    {
        tmp.clear();
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                tmp.push_back(j+1);
        for(int x=0;x<(int)tmp.size();x++)
            for(int y=x+1;y<(int)tmp.size();y++)
                val[i]+=a[tmp[x]][tmp[y]];
    }
    for(int i=0;i<(1<<n);i++)
    {
        my_popcount[i]=my_popcount[i>>1]+(i&1);
        useful[my_popcount[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)useful[i].size();j++)
        {
            int mask=useful[i][j];
            maxx[mask]=val[mask];
            for(int sub=mask;sub;sub=(sub-1)&mask)
                maxx[mask]=max(maxx[mask],maxx[sub]+val[mask^sub]);
        }
    ll ans=maxx[(1<<n)-1];
    printf("%lld\n",ans);
    return 0;
}
