#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001];
void dfs(int u,int r,int ans[],int a[],int &p){
    ans[u]=a[p];
    for(auto i: g[u]){
        if(i==r) continue;
        p--;
        dfs(i,u,ans,a,p);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,k;
    cin>>n;
    for(i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool c[n+1];
    memset(c,0,sizeof(c));
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int s=0;
    for(i=0;i<n-1;i++) s+=a[i];
    int ans[n+1];
    int p=n-1;
    dfs(1,-1,ans,a,p);
    cout<<s<<endl;
    for(i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;

}


