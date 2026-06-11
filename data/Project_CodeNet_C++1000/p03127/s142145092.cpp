#include <bits/stdc++.h>
using namespace std;

#define ll long long
int gcd(ll a, ll b) {
  return a % b ? gcd(b, a%b) : b;
}
int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) cin >> A[i]; 
  
  ll ans = A[0];
  
  for (int i = 0; i < N-1; i++) {
    ans = gcd(ans, A[i+1]);
  }
  
  cout << ans << endl;
        
}