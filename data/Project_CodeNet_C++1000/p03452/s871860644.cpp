#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair

vector<pair<int,int> > edge[100100];
int in_deg[100100];
int po[100100];

main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)po[i]=-1;
    for(int i=0;i<m;i++)
    {
        int l,r,d;
        scanf("%d %d %d",&l,&r,&d);
        edge[l].PB(MP(r,d));
        in_deg[r]++;
    }
    int err=0;
    for(int i=1;i<=n;i++)
    {
        if(in_deg[i]==0)
        {
            po[i]=0;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int nw=q.front();
                q.pop();
                for(int i=0;i<edge[nw].size();i++)
                {
                    int go=edge[nw][i].F;
                    int where=edge[nw][i].S+po[nw];
                    //printf("%d %d %d\n",go,where,po[go]);
                    if(po[go]!=-1)
                    {
                        if(where!=po[go])
                        {
                            err=1;
                        }
                    }
                    else
                    {
                        po[go]=where;
                        if(where>1e9)err=1;
                        q.push(go);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        //printf("%d\n",po[i]);
        if(po[i]==-1)err=2;
    }
    //printf("%d",err);
    if(err==0)printf("Yes\n");
    else printf("No\n");
}
