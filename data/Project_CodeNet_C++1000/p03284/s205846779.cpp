#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  int ans;
  if(a % b == 0) ans = 0;
  else ans = 1;
  cout << ans << endl;
  return 0;
}
