#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

vector<vector<int>> v(100100);
vector<int> col(100100,-1);
ll g[] = {0,0};
bool dfs(int ov,int pre){
  if(col[ov] != -1 && ov != pre){
    if(col[ov] == col[pre])return false;
    else return true;
  }
  bool is = true;
  col[ov] = 1-col[pre];
  g[col[ov]]++;
  for(auto nv: v[ov])is = is && dfs(nv,ov);
  return is;
}

int main(){
  
  ll n,m;
  cin >> n >> m;
  rep(i,m){
    int a,b;cin >> a >> b;
    a--,b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  col[0] = 0;
  bool is = dfs(0,0);
  cout << (is ? g[1]*g[0]-m : n*(n-1)/2-m) << endl;
  


  return 0;
}