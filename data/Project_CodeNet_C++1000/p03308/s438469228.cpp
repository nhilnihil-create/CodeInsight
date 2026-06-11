#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
using vi = vector<int>;
using vll = vector<ll>;
const ll INF = 1LL<<60;

int main(){
  int n; cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int ans = 0;

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int now = abs(a[i] - a[j]);
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}
