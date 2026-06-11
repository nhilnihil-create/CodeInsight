#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int n,a,b,c;
vector<int>l;

int dfs(int v,int as,int bs,int cs){
  if(v == n){
    if(as*bs*cs == 0) return 1e9;
    return abs(a-as)+abs(b-bs)+abs(c-cs);
  }
  int res = dfs(v+1,as,bs,cs);
  res = min(res,dfs(v+1,as+l[v],bs,cs)+(as?10:0));
  res = min(res,dfs(v+1,as,bs+l[v],cs)+(bs?10:0));
  res = min(res,dfs(v+1,as,bs,cs+l[v])+(cs?10:0));
  return res;
}

int main() {
  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i,0,n) cin >> l[i];
  int ans = dfs(0,0,0,0);
  cout << ans << endl;
}