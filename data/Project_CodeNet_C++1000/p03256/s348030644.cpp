#include <bits/stdc++.h>
#define maxn 200100

using namespace std;

int n,m,in[maxn],num[maxn][3],col[maxn];
string s;
vector<int> g[maxn],dead;

int main() {
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<n;i++) col[i]=(s[i]=='A');
    for (int i=1,u,v;i<=m;i++) {
        cin>>u>>v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        num[u][col[v]]++;
        num[v][col[u]]++;
    }
    for (int i=0;i<n;i++)
        if (num[i][0]==0 || num[i][1]==0) {
            dead.push_back(i);
            in[i]=1;
        }
    for (int i=0;i<dead.size();i++) {
        int u = dead[i];
        for (auto v : g[u]) {
            if (in[v]) continue;
            num[v][col[u]]--;
            if (num[v][0]==0 || num[v][1]==0) {
                dead.push_back(v);
                in[v]=1;
            }
        }
    }
    if (dead.size()==n) cout<<"No";
    else cout<<"Yes";
}
