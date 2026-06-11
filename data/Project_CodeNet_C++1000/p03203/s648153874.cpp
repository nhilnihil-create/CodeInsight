#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
vector<int>v[N];
int main()
{
    scanf("%d%d",&n,&m);
    int k;scanf("%d",&k);
    while(k--)
    {
        int x,y;scanf("%d%d",&x,&y);
        v[y].push_back(x);
    }
    v[1].push_back(n+1);
    for(int i=1;i<=m;i++) sort(v[i].begin(),v[i].end());
    int l=0,r=n+1;
    for(int i=1;i<=m;i++)
    {
        l++;
        if(l>=r) break;
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]==l) l++;
            else if(v[i][j]>l)
            {
                r=min(r,v[i][j]);
                break;
            }
        }
    }
    printf("%d\n",r-1);
}
