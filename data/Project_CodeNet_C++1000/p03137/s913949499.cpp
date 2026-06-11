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
  if(n >= m){
    cout << 0 << endl;
    return 0;
  }
  vector<int> x(m);
  for(int i = 0; i < m; i++) cin >> x[i];

  sort(x.begin(), x.end());

  vector<int> d;

  for(int i = 1; i < m; i++){
    int dd = abs(x[i-1] - x[i]);
    d.push_back(dd);
  }
  sort(d.begin(), d.end());

  int ans = 0;
  for(int i = 0; i < m-n; i++){
    ans += d[i];
  }
  cout << ans << endl;
  return 0;
}
