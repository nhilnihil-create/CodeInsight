#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

int fa[200],p[200][200],vis[200];

vector<int>ve[200];

int a[200],b[200],c[200],d[200];

int dfs(int x)
{
    for (auto v:ve[x]){
        if(!vis[v]){
            vis[v]=1;
            if(fa[v]==-1 || dfs(fa[v])){
               fa[v]=x;
               return 1;
            }
        }
    }
    return 0;
}
int n;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    memset(fa,-1,sizeof fa);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>c[i]>>d[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[j]>a[i] && d[j]>b[i]) {
                ve[i].push_back(j);
              //  ve[j].push_back(i);
            }
        }
    }
    int ans=0;

    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
