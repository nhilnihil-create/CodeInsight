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

int main(){
  int n,m; cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  if(n >= m){
    cout << 0 << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  vector<int> dist;
  for(int i = 1; i < m; i++){
    dist.push_back(a[i]-a[i-1]);
  }
  sort(dist.begin(), dist.end());
  int ans = 0;
  for(int i = 0; i < m-n; i++){
    ans += dist[i];
  }
  cout << ans << endl;
  return 0;
}
