#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;

int n,m,vis[100001],dist[100001];
vector<pii> adj[100001];

bool solve(int s) {
    queue<int> que;
    que.push(s);
    vis[s]=1;
    while(!que.empty()) {
        int cur=que.front();que.pop();
        for(auto &it:adj[cur]) {
            if(!vis[it.se]) {
                dist[it.se]=dist[cur]+it.fi;
                vis[it.se]=1;
                que.push(it.se);
            } else if(dist[it.se]!=dist[cur]+it.fi) return false;
        }
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        adj[u].push_back(pii(c,v));
        adj[v].push_back(pii(-c,u));
    }

    for(int i=1;i<=n;i++) if(!vis[i]) {
        if(!solve(i)) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    
    return 0;
}
