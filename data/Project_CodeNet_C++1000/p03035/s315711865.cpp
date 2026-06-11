#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;

  int ans;
  if(a>=13) ans = b;
  else if(6<=a && a<=12) ans = b/2;
  else ans = 0;

  cout << ans << endl;  

  return 0;
}
