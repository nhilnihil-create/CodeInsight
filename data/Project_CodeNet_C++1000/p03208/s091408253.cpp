#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,k; cin >> n >> k;
  vector<ll> h(n+1); for(int i = 1;i<=n;i++) cin >> h[i];

  sort(h.begin(),h.end());
  
  ll ans = INF_LL;
  for(int i = 1;i<=n;i++){
    if(i+k-1>n) break;
    ans = min(ans,h[i+k-1]-h[i]);
  }

  cout << ans << endl;
  
  return 0;
}
