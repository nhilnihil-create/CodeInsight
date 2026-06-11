#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int d,n; cin >> d >> n;

  int ans;
  if(n<=99) ans = pow(100,d)*n;
  else ans = pow(100,d)*101;

  cout << ans << endl;
  
  return 0;
}
