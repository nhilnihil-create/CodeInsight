#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int>ve[N];
int c[N];
int num[N];
int cnt,ans;
void dfs(int u,int f){
    for(int i=0;i<ve[u].size();i++){
        int v=ve[u][i];
        if(v!=f){
            num[v]=c[cnt--];
            dfs(v,u);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    sort(c,c+n);
    num[1]=c[n-1];
    cnt=n-2;
    ans=0;
    dfs(1,0);
    for(int i=0;i<n-1;i++) ans+=c[i];
    printf("%d\n",ans);
    printf("%d",num[1]);
    for(int i=2;i<=n;i++) printf(" %d",num[i]);
}
