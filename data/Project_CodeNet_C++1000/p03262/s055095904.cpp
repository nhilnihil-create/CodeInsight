#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

long long GCD(long long x, long long y) {
    return y ? GCD(y, x%y) : x;
}

int main(){
  ll n, x;
  cin >> n;
  vector<ll> vec(n+1);
  rep(i, n+1) cin >> vec[i];
  sort(all(vec));
  ll gcd = vec[1]-vec[0];
  rep(i, n) gcd = GCD(gcd, vec[i+1]-vec[i]);
  cout << gcd << endl;
  return 0;
}
    
