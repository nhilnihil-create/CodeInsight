#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

ll n,m;
vector<int> G[100010];
int color[100010];

bool dfs(int v,int c){
    color[v]=c;
    for(int u:G[v]){
        if(color[u]==c)return false;
        if(color[u]==0&&!dfs(u,-c))return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    ll ans;
    if(dfs(0,1)){
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(color[i]==1)cnt++;
        }
        ans=cnt*(n-cnt)-m;
    }else{
        ans=n*(n-1)/2-m;
    }
    cout<<ans<<endl;
}
