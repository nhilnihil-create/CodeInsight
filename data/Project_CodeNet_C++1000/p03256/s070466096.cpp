#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int maxn=2e5+7;
char a[maxn];
int in[maxn][2];
int vis[maxn];
queue<int> q;
int n,m;
vector<int>mp[maxn];

int main()
{
    n=read();m=read();
    scanf("%s",a+1);
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        mp[u].push_back(v);
        mp[v].push_back(u);
        in[u][a[v]-'A']++;
        in[v][a[u]-'A']++;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(in[i][0]==0||in[i][1]==0)q.push(i),res++,vis[i]=1;
    }
//    for(int i=1;i<=n;i++){
//        if(vis[i])printf("%d ",i);
//    }
//    puts("");
//    printf("fuck %d %d %d\n",res,in[4][1],in[4][0]);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=0;i<mp[x].size();++i){
//            if(vis[i])continue;
            int now=mp[x][i];
//            printf("asd %d %d\n",x,now);
            in[now][a[x]-'A']--;
            if(in[now][a[x]-'A']==0&&vis[now]==0){
                q.push(now);
                vis[now]=1;
                res++;
            }
        }
    }
//    printf("test %d\n",res);
    if(res!=n)puts("Yes");
    else puts("No");
    return 0;
}
