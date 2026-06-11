#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

vector<vector<int>> g;
vector<int> ans;

int main(){
  int n; cin >> n;
  vector<int> v(n), c(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  for(int i = 0; i < n; ++i) cin >> c[i];
  int ans = 0;
  for(int bit = 0; bit < (1<<n); ++bit){
    int a = 0, b = 0;
    for(int i = 0; i < n; ++i){
      if((bit >> i) & 1){
        a += v[i]; b += c[i];
      }
    }
    ans = max(ans, a - b);
  }
  cout << ans << endl;
  return 0;
}
