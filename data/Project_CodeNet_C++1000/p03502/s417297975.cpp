#include <bits/stdc++.h>
using namespace std;

int main() {
 int N , f , x;
 f = 0;
 x = 1;
 cin >> N;
 for (int i=0; i < 8; i++) {
   if ( N / x == 0 ) {
     break;
   }
   else {
   f += N % (x * 10) /x;
   x *= 10;
   }
 }
 if (N % f == 0) {
   cout << "Yes" << endl;
 }
 else {
   cout << "No" << endl;
 }
}