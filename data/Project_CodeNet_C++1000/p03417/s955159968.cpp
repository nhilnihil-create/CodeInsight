#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e6;
int t[5][5];
ll h,a,b,c,d,e;
int ans = 1;
bool memo[15][15] = {0};
int main(){
  ll m,n;
  cin >> n >> m;
  ll ans=0;
  if(n==1&&m==1)ans=1;
  else if(n==1 || m==1) ans = m*n-2;
  else ans = m*n - (2*(n+m)-4);
  cout << ans << endl;
  return 0;
}
