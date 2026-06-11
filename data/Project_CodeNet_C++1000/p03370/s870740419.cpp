#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,x; cin >> n >> x;
  vector<int> m(n); rep(i,n) cin >> m[i];

  sort(m.begin(),m.end());
  int ans = n;
  rep(i,n) x-=m[i];
  
  ans += x/m[0];

  cout << ans << endl;
  
  return 0;
}
