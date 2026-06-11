#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  ll n,m,d;
  cin>>n>>m>>d;
  ll tmp = d;
  if(d==0) tmp = n;
  else if(2*d >= n) tmp = n;
  else tmp += d + (n-2*d)*2;
  //cout << tmp << endl;
  double ans = tmp/double(n*n)*(m-1);
  cout << setprecision(10) << ans << endl;
  return 0;
}
