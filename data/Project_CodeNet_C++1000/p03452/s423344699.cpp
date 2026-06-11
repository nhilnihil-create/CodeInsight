#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[100005];
int in[100005],mk[100005];
main()
{
	int t,p,a,b,w;
    scanf("%d%d",&t,&p);
    for(int i = 0;i < p;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        v[a].push_back(make_pair(b,w));
        v[b].push_back(make_pair(a,-w));
    }
    for(int i = 1;i <= t;i++)
    {
        mk[i]=-1.1e9;
    }
    for(int i = 1;i <= t;i++)
    {
        if(mk[i]==-1.1e9)
        {
            mk[i]=0;
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                int cur=q.front();
                for(int j = 0;j < v[cur].size();j++)
                {
                    int go=v[cur][j].first,wa=v[cur][j].second;
                    if(mk[go]==-1.1e9)
                    {
                        mk[go]=mk[cur]+wa;
                        q.push(go);
                    }
                    else if(mk[go]!=mk[cur]+wa)
                    {

                        printf("No");
                        return 0;
                    }
                }
                q.pop();
            }
        }
    }
    printf("Yes");
}
