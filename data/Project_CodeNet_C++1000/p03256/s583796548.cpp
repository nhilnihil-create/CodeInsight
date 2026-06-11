#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5;
queue<int>q;
int du[maxn+10][2];
int n,m;
string s;
vector<int>ve[maxn+10];
bool vis[maxn+10];
int cnt;
int main()
{
    while(cin>>n>>m)
    {
        cnt=0;
        cin>>s;
        for(int i=1; i<=n; i++)
            du[i][1]=0,du[i][0]=0,ve[i].clear(),vis[i]=false;
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            du[u][s[v-1]=='B']++;
            du[v][s[u-1]=='B']++;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
            if(du[i][0]==0||du[i][1]==0)
                if(!vis[i])
                    q.push(i),vis[i]=true,cnt++;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0; i<ve[u].size(); i++)
            {
                int v=ve[u][i];
                if(!vis[v])
                    if(--du[v][s[u-1]=='B']==0)
                        q.push(v),vis[v]=true,cnt++;
            }
        }
        if(cnt==n)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
