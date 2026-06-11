#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

lli n;
vll x,y,u,v;
lli m = 35;
lli mod;
vll d;
lli dist;

void error(){
  cout << -1 << endl;
  exit(0);
}

void solve(lli u, lli v){
  vll ans_u = vll(m);
  vll ans_v = vll(m);
  lli x = (u+dist)/2;
  lli y = (v+dist)/2;
  for(lli i = 0;i < m;i++){
    ans_u[i] = (x&d[i]) ? 1 : -1;
    ans_v[i] = (y&d[i]) ? 1 : -1;
  }
  for(lli i = 0;i < m;i++){
    if(ans_u[i] == 1 && ans_v[i] == 1) cout << 'R';
    if(ans_u[i] == 1 && ans_v[i] == -1) cout << 'U';
    if(ans_u[i] == -1 && ans_v[i] == 1) cout << 'D';
    if(ans_u[i] == -1 && ans_v[i] == -1) cout << 'L';
  }
  if(mod==0) cout << 'R';
  cout << endl;
}

int main(){
  cin >> n;
  x = vll(n);
  y = vll(n);
  u = vll(n);
  v = vll(n);
  for(lli i = 0;i < n;i++) cin >> x[i] >> y[i];
  for(lli i = 0;i < n;i++) u[i] = x[i]+y[i], v[i] = x[i]-y[i];
  mod = abs(u[0])%2;
  if(find_if(u.begin(),u.end(),[mod](lli x){return abs(x)%2 != mod;}) != u.end()) error();
  if(find_if(v.begin(),v.end(),[mod](lli x){return abs(x)%2 != mod;}) != v.end()) error();
  for(lli i = 1, j = 0;j < m;j++,i <<= 1) d.push_back(i);
  dist = accumulate(d.begin(),d.end(),0ll);
  if(mod == 0) d.push_back(1ll);
  if(mod == 0) cout << m+1 << endl;
  else cout << m << endl;
  for(lli i = 0;i < d.size()-1;i++) cout << d[i] << " ";
  cout << d[d.size()-1] << endl;
  for(lli i = 0;i < n;i++){
    solve(u[i],v[i]);
  }
  return 0;

}
