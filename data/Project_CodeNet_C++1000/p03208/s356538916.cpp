#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
using vi = vector<int>;
using vll = vector<ll>;
const ll INF = 1LL<<60;

int main(){
  int n,k; cin >> n >> k;

  vi h(n);
  rep(i,n) cin >> h[i];
  sort(h.begin(), h.end());
  reverse(h.begin(), h.end());
  int ans = 1<<30;
  for(int i = 0; i < n-k+1; i++){
    int now = h[i] - h[i+k-1];
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
