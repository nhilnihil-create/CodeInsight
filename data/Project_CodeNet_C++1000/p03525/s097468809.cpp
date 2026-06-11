#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,tot,d[N],vis[N];
vector<int>v;
int main()
{
    scanf("%d",&n);
    vis[0]++;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);vis[x]++;
    }
    for(int i=0;i<12;i++)
        if(vis[i]>=3){printf("0\n");return 0;}
    else
    {
        if(vis[i]==2) d[++tot]=i,d[++tot]=24-i;
        else if(vis[i]) v.push_back(i);
    }
    if(vis[12]>=2){printf("0\n");return 0;}
    else if(vis[12]) d[++tot]=12;
    int up=1<<v.size();
    int ans=0;
    for(int i=0;i<up;i++)
    {
        int sum=tot;
        for(int j=0;j<v.size();j++)
            if(i>>j&1)
            d[++sum]=24-v[j];
            else d[++sum]=v[j];
        int res=24;
        for(int j=1;j<=sum;j++)
            for(int k=j+1;k<=sum;k++)
        {
            int p=abs(d[k]-d[j]);
            res=min(res,min(p,24-p));
        }
        ans=max(ans,res);
    }
    printf("%d\n",ans);
}
