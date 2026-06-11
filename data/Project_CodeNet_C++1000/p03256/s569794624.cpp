#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;
vector< vector<int> > G(N);
vector< vector<int> > c(N,vector<int>(2));
//c[u][0]=隣接するAの数,c[u][1]=隣接するBの数}
vector<bool> deleted(N);
string s;

void check(int i){
  if(deleted[i]) return;
  deleted[i] = true;
  for(int v : G[i]){
    if(deleted[v]) continue;
    (s[i] == 'A' ? c[v][0] : c[v][1]) -= 1;
    if(c[v][0] == 0 || c[v][1] == 0) check(v);
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m; cin >> n >> m >> s;
  for(int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
    (s[a] == 'A' ? c[b][0] : c[b][1]) += 1;
    (s[b] == 'A' ? c[a][0] : c[a][1]) += 1;
  }

  for(int i = 0; i < n; i++){
    if(c[i][0] == 0 || c[i][1] == 0) check(i);
  }

  for(int i = 0; i < n; i++){
    if(!deleted[i]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
