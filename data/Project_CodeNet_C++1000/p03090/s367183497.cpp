#include <bits/stdc++.h>
using namespace std;
int edge[111][111];
#define rep(i,s,t) for(int i=s;i<t;i++)
#define pii pair<int,int>
int main()
{
    int n;scanf("%d",&n);
    vector<pii> res;
    int tmp=n/2*2;
    rep(i,1,tmp+1)edge[i][i]=edge[i][tmp-i+1]=1;
    rep(i,1,n+1)rep(j,i+1,n+1)if(!edge[i][j])
        res.emplace_back(i,j);
    printf("%d\n",res.size());
    for(pii p:res)printf("%d %d\n",p.first,p.second);
}