#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int maxpizza, minpizza;
  
  if(X > Y){
    maxpizza = X; minpizza = Y;
  } else {
    maxpizza = Y; minpizza = X;
  }
  
  int ans = 0;
  
  if(2 * C <= A && 2 * C <= B) {
    ans += 2 * C * maxpizza;
  } else if (2 * C <= A + B) {
    ans += minpizza * 2 * C;
    if (X > Y) {
      if (2 * C < A) {
        ans += 2 * C * (maxpizza - minpizza);
      } else {
        ans += A * (maxpizza - minpizza);
      } 
    } else {
      if (2 * C < B) {
        ans += 2 * C * (maxpizza - minpizza);
      } else {
        ans += B * (maxpizza - minpizza); 
      }
    }
  } else {
    ans += A * X + B * Y;
  }
  cout << ans << endl;  
}  