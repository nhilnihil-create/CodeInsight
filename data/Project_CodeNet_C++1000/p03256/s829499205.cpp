#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=200005;

int N,M;
char s[MAXN];
vector<int> adj[MAXN];
int cnt[MAXN][2];
queue<int> Q;
bool del[MAXN];

int main()
{
    scanf("%d%d%s",&N,&M,s+1);
    for(int i=1;i<=M;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        cnt[a][s[b]-'A']++;
        cnt[b][s[a]-'A']++;
    }
    for(int i=1;i<=N;i++)
        if(cnt[i][0]==0||cnt[i][1]==0)
            Q.push(i),del[i]=true;
    int tmp=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        tmp++;
        for(auto v:adj[u])
            if(!del[v])
            {
                cnt[v][s[u]-'A']--;
                if(cnt[v][s[u]-'A']==0)
                {
                    del[v]=true;
                    Q.push(v);
                }
            }
    }
    if(tmp<N)
        puts("Yes");
    else
        puts("No");

    return 0;
}
