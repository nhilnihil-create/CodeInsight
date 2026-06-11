#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  
  const long long inf = pow(10, 18);
  long long ans = a - b;
  if(abs(ans) > inf){
    cout << "Unfair" << endl;
    return 0;
  }
  if(k % 2) cout << -ans << endl;
  else cout << ans << endl;
}