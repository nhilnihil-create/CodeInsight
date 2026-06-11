#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int m = min(X,Y);
  
  int ans = 0;
  
  //1st step
  int firstSumA = A * m;
  int firstSumB = B * m;
  int firstSumAB = firstSumA + firstSumB;
  int firstSumHalf = C * 2 * m;
  
  if (firstSumAB >= firstSumHalf){
    if ( A * (X - m) + B * (Y - m) >= C * 2 * (X + Y - 2 * m)) {
      ans = C * 2 * (X + Y - m);
    }
    else {
      ans = firstSumHalf + A * (X - m) + B * (Y - m);
    }
  }
  else { 
    if ( A * (X - m) + B * (Y - m) >= C * 2 * (X + Y - 2 * m)){
      ans = firstSumAB + C * 2 * (X + Y - 2 * m);
    }
    else {
      ans = firstSumAB + A * (X - m) + B * (Y - m);
    }
  }
  
  cout << ans << endl;
  
}