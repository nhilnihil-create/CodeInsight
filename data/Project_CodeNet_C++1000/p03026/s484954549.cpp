#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int n;
vector<vector<int>> G;
vector<int> ans;
vector<int> c;
int id=0;

void dfs(int v,int p=-1){
    ans[v]=c[id];
    id++;
    for(auto nv : G[v]){
        if(nv==p) continue;
        dfs(nv,v);
    }
}

int main(){
    cin>>n;
    G.resize(n);
    ans.resize(n);

    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    c.resize(n);
    int sum=0;
    rep(i,n){
        cin>>c[i];
        sum+=c[i];
    }
    sort(all(c));
    reverse(all(c));
    sum-=c[0];
    cout<<sum<<endl;

    dfs(0);
    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
}