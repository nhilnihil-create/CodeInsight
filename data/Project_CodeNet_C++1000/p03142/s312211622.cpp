#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[100005];
set<int>s[100005];
int par[100005];
main()
{
    int n,m,i,j,x,y,ind;
    cin>>n>>m;
    for(i=1;i<=n-1+m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        s[y].insert(x);
    }
    for(i=1;i<=n;i++)
    {
        if(s[i].empty())
        {
            ind=i;break;
        }
    }
    queue<int>q;
    q.push(ind);
    while(!q.empty())
    {
        int top=q.front();q.pop();
        for(int i=0;i<v[top].size();i++)
        {
            int z=v[top][i];
            if(s[z].size()==1)
            {
                  q.push(z);par[z]=top;
            }
            s[z].erase(top);
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<par[i]<<endl;
    }
}
