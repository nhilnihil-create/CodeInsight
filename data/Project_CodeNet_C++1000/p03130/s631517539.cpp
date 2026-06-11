#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool vis[4];
int level[4];
vector<int> v[4];
void dfs( int s, int l){
    vis[s]=true;
    level[s]=l;
    for(int i=0;i<(int)v[s].size();++i){
        if(!vis[v[s][i]])
        dfs(v[s][i],l+1);
    }
}
int32_t main()
{
    for(int i=0;i<3;++i){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<=3;++i){
        for(int j=0;j<=3;++j)
        vis[j]=false;
        dfs(i,0);
        for(int i=0;i<=3;++i)
        if(level[i]==3){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
