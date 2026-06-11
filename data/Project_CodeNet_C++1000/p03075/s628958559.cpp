#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int a[5];
   int k;
   rep(i, 5) {
       cin >> a[i];
   }
   cin >> k;

   for (int i=0; i<4; i++) {
       for (int j=i+1; j<5; j++) {
           if (a[j] - a[i] > k) {
               cout << ":(" << endl;
               return 0;
           }
       }
   }

   cout << "Yay!" << endl;
}