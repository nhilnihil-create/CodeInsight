#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int n,x; cin >> n >> x;

  vector<int> m(n);
  int ans = n;
  for(int i = 0; i < n; i++){
    cin >> m[i];
    x -= m[i];
  }
  sort(m.begin(), m.end());
  ans += x / m[0];
  cout << ans << endl;
  return 0;
}
