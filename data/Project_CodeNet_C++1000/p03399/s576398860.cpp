#include<iostream>
 
using namespace std;
 
int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
 if (A >= B && C >= D) {
   cout << B + D;
 }
 else if (A >= B && D >= C) {
   cout << B + C;
 }
  else if (B >= A && C >= D) {
   cout << A + D;
 }
  else if (B >= A && D >= C) {
   cout << A+ C;
 }
}