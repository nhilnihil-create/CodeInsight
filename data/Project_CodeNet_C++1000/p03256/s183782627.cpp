#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)

int n,m;

struct e{
    int u;
    int v;
    int k;
    int t;
};
vector<vector<e>> G;
vector<e> es;

vector<int> seen;
bool res;

bool dfs(int i){
    if(seen[i]==0){
        res = true;
        return 0;
    }
    else if(seen[i]==-1){
        seen[i] = 0;
        int u = es[i].v, t = es[i].t;
        t = (t+1)%4;
        for(e ee:G[u]){
            if(ee.t==t){
                dfs(ee.k);
            }
        }
        seen[i] = 1;
    }
    return 0;
}


int main(int argc, char const *argv[]) {
    cin>>n>>m;
    string s;cin>>s;
    G = vector<vector<e>>(n, vector<e>(0));
    seen = vector<int>(2*m, -1);
    res = false;
    es = vector<e>(0);
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        u--;
        v--;
        e e1;
        e1.u = u;
        e1.v = v;
        e1.k = 2*i;
        int t = 0;
        if(s[u]=='A'&&s[v]=='B')t=1;
        if(s[u]=='B'&&s[v]=='B')t=2;
        if(s[u]=='B'&&s[v]=='A')t=3;
        e1.t = t;
        G[u].push_back(e1);
        es.push_back(e1);
        int tmp = v;
        v = u;
        u = tmp;
        e e2;
        e2.u = u;
        e2.v = v;
        e2.k = 2*i+1;
        t = 0;
        if(s[u]=='A'&&s[v]=='B')t=1;
        if(s[u]=='B'&&s[v]=='B')t=2;
        if(s[u]=='B'&&s[v]=='A')t=3;
        e2.t = t;
        G[u].push_back(e2);
        es.push_back(e2);
    }
    int l = 0;
    for(int i=0;i<2*m;++i){
        if(seen[i]==-1)dfs(i);
    }
    if(res)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}