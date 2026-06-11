#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int ans = 1<<30,a,b,c,n;
vector<int> l;

int solve(vector<int> d){
  int p = 0,aa = 0,bb = 0,cc = 0;
  for(int i = 0; i < n; i++){
    if(d[i] == 0) aa += l[i];
    else if(d[i] == 1) bb += l[i];
    else if(d[i] == 2) cc += l[i];
    if(d[i] != 3) p += 10;
  }
  if(aa == 0 || bb == 0 || cc == 0){
    return 1<<30;
  }
  p += abs(a - aa);
  p += abs(b - bb);
  p += abs(c - cc);
  p -= 30;
    return p;
}

void dfs(vector<int> d){
  if(d.size() == n){
    int now = solve(d);
    ans = min(ans,now);
    return;
  }
  for(int i = 0; i < 4; i++){
    d.push_back(i);
    dfs(d);
    d.pop_back();
  }
}

int main(){
  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i,n) cin >> l[i];
  vector<int> d;
  dfs(d);
  cout << ans << endl;
  return 0;
}
