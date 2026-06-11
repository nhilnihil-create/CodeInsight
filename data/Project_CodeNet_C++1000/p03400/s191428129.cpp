#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, D, X, a, ans = 0;
  cin >> N >> D >> X;
  
  for (int i = 0; i < N; i++) {
    cin >> a;   
    ans += (D-1)/a+1;
  }
  
  cout << ans+X << endl;
}