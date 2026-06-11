#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int A, B, K;
   cin >> A >> B >> K;

   for (int i = 1; i <= K; i ++) {
     if (i % 2 == 1) {
       int tmp;
       tmp = A - A / 2 - A % 2;
       B = B + A / 2;
       A = tmp;
     }
     else {
       int tmp;
       tmp = B - B / 2 - B % 2;
       A = A + B / 2;
       B = tmp;
     }
   }

   cout << A << " " << B << endl;
  }
