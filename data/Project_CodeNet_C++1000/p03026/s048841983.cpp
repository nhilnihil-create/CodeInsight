#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  rep(i,n-1){
    int a,b;cin >> a >> b;
    a--,b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<int> c(n);
  rep(i,n)cin >> c[i];
  sort(ALL(c),greater<int>());
  queue<int> que;
  que.push(0);
  vector<int> res(n,-1);
  res[0] = c[0];
  int i = 1;
  ll k = 0;
  while(!que.empty()){
    int ov = que.front();que.pop();
    for(int nv : v[ov]){
      if(res[nv] != -1)continue;
      res[nv] = c[i];
      k += c[i];
      i++;
      que.push(nv);
    }
  }
  cout << k << "\n";
  rep(j,n)cout << res[j] << " ";
  cout << "\n";








  return 0;
}