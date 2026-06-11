#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> p(n); rep(i,n) cin >> p[i];
  sort(p.begin(),p.end());
  p[n-1] /= 2;

  int ans = 0;
  rep(i,n) ans+=p[i];
  cout << ans << endl;
  
  return 0;
}
