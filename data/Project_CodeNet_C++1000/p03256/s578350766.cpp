#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vi> g(n);
    rep(i,0,m) {
      int a,b;
      cin>>a>>b;
      --a,--b;
      g[a].eb(b);
      g[b].eb(a);
    }
    string X = "AABB";
    vector<vi> vis(n, vi(4,0));
    bool works = false;
    function<void(int,int)> dfs = [&](int x, int pos) {
      if(s[x] != X[pos]) return;
      if(vis[x][pos] == 1) works = true;
      if(vis[x][pos]) return;
      vis[x][pos] = 1;
      for(int y:g[x]) dfs(y, (pos+1)%4);
      vis[x][pos] = 2;
    };
    rep(pos,0,4) rep(x,0,n) dfs(x, pos);
    if(works) cout << "Yes" << endl;
    else      cout << "No" << endl;
    return 0;
}
