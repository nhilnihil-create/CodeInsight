#include <bits/stdc++.h>
using namespace std;

int main() {
 int A, B, C, X, Y;
 cin >> A >> B >> C >> X >> Y;
   
 int total = 0;
 if( A + B > 2*C ) total += 2*C * min(X, Y); 
 else total += (A + B) * min(X, Y); 
  
 if( A > 2*C && X == max(X, Y)) total += 2*C * (X - Y);
 else if( A <= 2*C && X == max(X, Y)) total += A * (X - Y); 
 else if( B > 2*C && Y == max(X, Y)) total += 2*C * (Y - X);
 else total += B * (Y - X);
  
 cout << total << endl;
      
}