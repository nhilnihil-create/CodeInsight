#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
 
int main(){
  ll n;
  cin >> n;
 
  ll res = 0;
 
  for (ll r = 1; r * r <= n; r++) {
    if ((n - r) % r == 0 && (n - r)/r > r) res += (n-r)/r;
  }
  cout << res << endl;
  return 0;
} 