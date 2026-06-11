#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+15,M = 2e5+5;

bool vis[N];

ll dp[N];

vector<pair<int,int> >adj[N];


void dfs(int node) {
    vis[node] = true;
    for(int i=0;i<adj[node].size();++i) {
        
        int nextNode = adj[node][i].first , ww = adj[node][i].second;
        if(!vis[nextNode]) {
            dp[nextNode] = dp[node] + ww;
            dfs(nextNode);
        } else {
            if(dp[node]+ ww != dp[nextNode]) {
                printf("No\n");
                exit(0);
            }
        }
    }
}
void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i) {
        int l,r,w;
        scanf("%d%d%d",&l,&r,&w);
        adj[l].push_back(make_pair(r,w));
        adj[r].push_back(make_pair(l,-w));
    }
    for(int i=1;i<=n;++i) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    printf("Yes\n");
}
int main() {
   //freopen("input.txt","r",stdin);
   solve();
}
