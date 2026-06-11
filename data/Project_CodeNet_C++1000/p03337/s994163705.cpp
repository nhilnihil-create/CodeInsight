#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int ans = A + B;
  if (ans < A - B) ans = A - B;
  if (ans < A * B) ans = A * B; 
    
  cout << ans << endl;
  
}