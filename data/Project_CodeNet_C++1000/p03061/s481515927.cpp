#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int gcd(ll a, ll b) { return b ? gcd(b, a%b) : a;}

int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  rep(i,n) cin >> vec[i];
  vector<ll> left(n+1, 0), right(n+1, 0);
  rep(i,n) left[i+1] = gcd(left[i], vec[i]);
  for(int i = n-1; i >= 0; i--) {
    right[i] = gcd(right[i+1], vec[i]);
  }
  int ans = 1;
  rep(i, n) {
    ans = max(ans, gcd(left[i], right[i+1]));
  }
  cout << ans << endl;
  
  


  return 0;
}