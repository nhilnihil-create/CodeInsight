#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
using ipair = pair<int,int>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
const int MOD=1000000007;
int main(){   
    int n;cin>>n;
    vector<vector<int>> to(n),c(n);
    rep(i,n-1){
        int a,b,w;
        cin>>a>>b>>w;a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
        c[a].push_back(w);
        c[b].push_back(w);
    }
    vector<int> ans(n,-1);
    queue<int> q;
    q.push(0);ans[0] = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        rep(i,to[u].size()){
            int v = to[u][i];
            if(ans[v]!=-1)continue;
            ans[v] = (ans[u]+c[u][i])%2;
            q.push(v);
        }
    }
    rep(i,n)cout<<ans[i]<<endl;
    return 0;
}