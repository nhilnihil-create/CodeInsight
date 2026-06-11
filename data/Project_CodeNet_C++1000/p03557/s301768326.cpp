#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {

  int N;
  cin >> N;
  int A[N], B[N], C[N];
  
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    A[i];
  }
  sort(A, A+N);
  for (ll i = 0; i < N; i++) {
    cin >> B[i];
  }
  sort(B, B+N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    C[i];
  }
  sort(C, C+N);
  
  
  ll ans = 0;
  // Bからきめる
  for (ll i = 0; i < N; i++) {
    ll a, c;
    // Aのきめかた
    a = lower_bound(A, A+N, B[i]) - A;
    
    // Cのきめかた
    c = N - (upper_bound(C, C+N, B[i]) - C);
    
    ans += a * c;
    
  }
  
  cout << ans << endl;
}