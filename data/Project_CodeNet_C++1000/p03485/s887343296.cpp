#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n, k;
  cin >> n >> k;
  int ans = (n+k)/2;
  if((n+k)%2!=0) ans++;
  cout << ans << endl;
  return 0;
}
