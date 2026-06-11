#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> G;
vector<int> c;
vector<int> d;
int ind=0;

void dfs(int cu,int pa){
    d[cu]=c[ind];
    ind++;
    for(auto nv : G[cu]){
        if(nv==pa) continue;
        dfs(nv,cu);
    }
}

int main(){
    int n;
    cin>>n;

    G.resize(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans=0;
    c.resize(n);
    d.resize(n);
    rep(i,n){
        cin>>c[i];
        ans+=c[i];
    }

    sort(all(c));
    reverse(all(c));
    ans-=c[0];

    dfs(0,-1);

    cout<<ans<<endl;
    rep(i,n) cout<<d[i]<<" ";
    cout<<endl;
}
