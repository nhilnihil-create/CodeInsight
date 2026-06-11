#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int color[100005];
vector<vector<int>> g;
bool dfs(int u,int c){
    color[u] = c;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(color[v] == c){
            return false;
        }
        if(color[v] == 0 && !dfs(v,-c) ){
            return false;
        }
    }
    return true;
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,m;
    cin >> n >> m;
    g.resize(n);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll B = 0 , W = 0;
    if(dfs(0,1)){
        for(int i=0;i<n;i++){
            if(color[i]==1){
                B++;
            }else if(color[i]==-1){
                W++;
            }
        }
        cout << B*W - m << endl;
    }else{
        cout << (n*(n-1))/2 - m << endl;
    }
}