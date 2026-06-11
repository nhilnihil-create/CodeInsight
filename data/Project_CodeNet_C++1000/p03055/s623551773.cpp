#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> T[N];
int f[N];
int res = 0;

void dfs(int u, int par){
  int mx1 = 0, mx2 = 0;
  for(auto x : T[u]){
    if(x == par) continue;
    dfs(x, u);
    f[u] = max(f[u], f[x] + 1);
    if(f[x]+1 >= mx1)
      mx2=mx1, mx1=f[x]+1;
    else if(f[x]+1 >= mx2)
      mx2 = f[x]+1;
  }
  res = max(res, mx1 + mx2);
}

int who[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int a, b;
  for(int i = 1; i < n; i ++ ){
    cin >> a >> b;
    T[b].push_back(a);
    T[a].push_back(b);
  }
  dfs(1,-1);
  who[0] = 1;
  for(int i = 1; i <= res; i ++ ){
    if(!who[i - 1]){
      who[i] = 1;
    }
    else if(i >= 2 && (!who[i-2])){
      who[i] = 1;
    }
  }
  if(who[res])
    cout << "First\n";
  else
    cout << "Second\n";
  return 0;
}
