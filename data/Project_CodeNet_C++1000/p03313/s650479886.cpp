#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)(1 << 18);

int a[N];
bool vis[N];
vector<pii> T[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int m = (1 << n);
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a[i];
    T[i].push_back(mp(a[i],i));
  }
  vis[0]=true;
  queue<int> bf;
  bf.push(0);
  int node;
  int nx;
  while(!bf.empty()){
    node = bf.front();
    bf.pop();
    sort(T[node].begin(), T[node].end());
    T[node].resize(unique(T[node].begin(), T[node].end()) - T[node].begin());
    reverse(T[node].begin(), T[node].end());
    while(T[node].size() > 2) T[node].pop_back();
    for(int i = 0 ; i < n; i ++ ){
      if((node & (1 << i))) continue;
      nx = (node | (1 << i));
      if(!vis[nx]){
        vis[nx]=true;
        bf.push(nx);
      }
      for(auto p : T[node]){
        T[nx].push_back(p);
      }
    }
  }
  int out = 0;
  for(int i = 1; i < m ; i ++ ){
    out = max(out, T[i][0].fi + T[i][1].fi);
    cout << out << "\n";
  }
  return 0;
}