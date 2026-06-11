#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll gcd (ll a , ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}
int main() {

   int T;
   cin >> T;
   ll A[T], B[T], C[T], D[T];

   for (int i = 0; i < T; i++) {
      cin >> A[i] >> B[i] >> C[i] >> D[i];
   }

   for (int i = 0; i < T; i++) {
      bool flg = false;
      ll Atmp = A[i];
      ll Btmp = B[i];
      ll Ctmp = C[i];
      ll Dtmp = D[i];
      if (Atmp < Btmp) {
         // cout << "1" << endl;
         flg = false;
      }
      else if (Btmp > Dtmp) {
         // cout << "2" << endl;
         flg = false;
      }
      else if (Btmp <= Ctmp) {
         // cout << "3" << endl;
         flg = true;
      }
      else {
         ll large = Btmp;
         ll small = Dtmp;
         if (large < Dtmp) {
            large = Dtmp;
            small = Btmp;
         }
         ll Amod = Atmp % gcd(large, small);
         if (Amod < 0) Amod += gcd(large, small);
         
         ll maxid = Btmp / gcd(large, small);
         // cout << "Amod " << Amod << endl;
         // cout << "maxid " << maxid << endl;
         // cout << Amod + gcd(large, small) * (maxid - 1) << endl;
         if (Amod + gcd(large, small) * (maxid - 1) > Ctmp) {
            // cout << "4" << endl;
            flg = false;
         }
         else {
            // cout << "5" << endl;
            flg = true;
         }
      }
      if (flg) cout << "Yes" << endl;
      else cout << "No" << endl;
   }
   return 0;
}
