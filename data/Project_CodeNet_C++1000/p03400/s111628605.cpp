#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  int d,x; cin >> d >> x;
  vector<int> a(n); rep(i,n) cin >> a[i];

  int ans = x;
  rep(i,d)
    rep(j,n)
    if(i*a[j]+1<=d) ans++;

  cout << ans << endl;
  
  return 0;
}
