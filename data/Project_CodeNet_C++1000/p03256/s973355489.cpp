#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 10;
vector<int> T[N];
int c[N][2];
int col[N];
bool delt[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  char q;
  for(int i = 1; i <= n; i ++ ){
    cin >> q;
    col[i]=q-'A';
  }
  int u, v;
  for(int i = 1; i <= m; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
    c[u][col[v]]++;
    c[v][col[u]]++;
  }
  queue<int> sh;
  for(int i = 1; i <= n; i ++ ){
    if(c[i][0] == 0 || c[i][1] == 0){
      sh.push(i);
      delt[i]=true;
    }
  }
  int node;
  while(!sh.empty()){
    node = sh.front();
    sh.pop();
    for(auto x : T[node]){
      c[x][col[node]]--;
      if((c[x][0] == 0 || c[x][1] == 0) && !delt[x]){
        sh.push(x);
        delt[x]=true;
      }
    }
  }
  bool ans = false;
  for(int i = 1; i <= n; i ++ ) ans |= !delt[i];
  if(ans)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
