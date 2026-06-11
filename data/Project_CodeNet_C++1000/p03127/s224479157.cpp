#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;



// 3 5 -> 3 2 -> 1 2 -> 1 1 .= 1 0
// 3 5 6 -> 3 2 0 ->
//10 6 -> 4 6 -> 4 2 -> 2 2 .> 2 0
//gcd

int gcd(int n, int m){
  if(n < m) swap(n,m);

  if(m==0) return n; // 0's deviser is all numbers.
  while(m > 0){
    int res = n%m;
    n = m;
    m = res;
  }
  return n;
}
//

int lcm(int n, int m){
  return m*n/gcd(n,m);
}




int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int ans = a[0];
  rep(i,n) ans = min(ans, gcd(ans,a[i]));
  cout << ans << endl;
}
