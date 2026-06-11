#include <bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
  int N;
  cin >> N;
  
  ll A[N];
  
  int minus = 0;
  ll absmin = 1000000000;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    ans += abs(A[i]);
    if (A[i] < 0)
      minus++;
    if (abs(A[i]) < absmin) absmin = abs(A[i]);
  }
  
  if (minus % 2) {
    cout << ans - 2 * absmin << endl;
  } else {
    cout << ans << endl;
  }
}