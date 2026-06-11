#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int n;
vector<int>to[10005];
vector<int>c;
ll mx=0;
vector<int>ans;
int cur=0;
void dfs(int u,int p=-1){
    ans[u]=c[cur];
    if(p!=-1)mx+=c[cur];
    cur++;
    for(int v:to[u]){
        if(v==p)continue;
        if(ans[v]!=-1)continue;
        dfs(v,u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    c.resize(n);
    rep(i,n)
    {
        int ci;
        cin>>ci;
        c.push_back(ci);
    }
    sort(c.rbegin(),c.rend());
    ans.assign(n,-1);
    dfs(0);
    cout<<mx<<endl;
    rep(i,n){
        printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
    return 0;
}