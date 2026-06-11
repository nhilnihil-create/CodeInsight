#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const int MAX = 1e5;

vector<int> g[MAX];
vector<int> color(MAX,0);

bool dfs(int v, int c){
    color[v] = c;
    rep(i,g[v].size()){
        if(color[g[v][i]] == c) return false;
        if(color[g[v][i]] == 0 && !dfs(g[v][i],-c)) return false; 
    }
    return true;
}

int main(){
    ll n, m;
    cin >> n >> m;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(dfs(0,1)){
        ll b = 0;
        rep(i,n) if(color[i] == 1) b++;
        cout << b*(n-b) - m << endl;
    } else {
        cout << n*(n-1)/2 - m << endl;
    }
    return 0;
} 