#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int main(void){
  int a,b,c; cin >> a >> b >> c;
  int ans;

  if(b>=c*a) ans = c;
  else ans = b/a;

  cout << ans << endl;
  
  return 0;
}
