#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,a,b,c,ans=1e9;

void dfs(vector<int>x, int m=0){
    int s=x.size();
    if(s<3)return;
    rep(i,s)rep(j,s)rep(k,s){
        if(i==j||j==k||k==i)continue;
        int cnt=abs(x[i]-a)+abs(x[j]-b)+abs(x[k]-c);
        ans=min(ans,cnt+m*10);
    }
    if(s==3)return;
    for(int i=0; i<s; ++i)for(int j=i+1; j<s; ++j){
        vector<int>nx;
        rep(k,s)if(k!=i&&k!=j)nx.push_back(x[k]);
        nx.push_back(x[i]+x[j]);
        dfs(nx,m+1);
    }
}

int main(){
    cin>>n>>a>>b>>c;
    vector<int>l(n);
    rep(i,n)cin>>l[i];
    dfs(l);
    cout<<ans<<endl;
}