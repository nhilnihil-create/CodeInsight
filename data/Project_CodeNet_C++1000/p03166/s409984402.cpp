#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// int visited[100001];
ll dis[100001];
// int ans;

ll dfs(int i,vector <int> vi[]){

    if(dis[i]!=-1) return dis[i];

    ll temp=0;
    for(auto it:vi[i]){
            temp=max(temp,1+dfs(it,vi));
    }

    return dis[i]=temp;
}

int main(){
    fast;
    int m=1;
    // cin>>m;

    while(m--)
    {
        memset(dis,-1,sizeof(dis));
        int n,m;
        cin>>n>>m;

        int a,b;
        vector <int> vi[n+1];

        for(int i=0;i<m;i++){
            cin>>a>>b;
            vi[a].push_back(b);
        }
        ll maxAns=0;
        // cerr<<"working";
        for(int i=1;i<=n;i++){
            maxAns=max(maxAns,dfs(i,vi));
        }
        cout<<maxAns<<'\n';
    }
}