#include <bits/stdc++.h>
using namespace std;


int main() {
   
   int n; 
   cin >> n;
   
   int maxA = n / 4;
   int maxB = n / 7;
   
   bool ans = false;
   for (int i=0; i<=maxA; i++) {
       for (int j=0; j<=maxB; j++) {
           int sum = 4 * i + 7 * j;
           if (sum ==n) ans = true;
       }
   }
   if (ans) cout << "Yes" << endl;
   else cout << "No" << endl;
    
}