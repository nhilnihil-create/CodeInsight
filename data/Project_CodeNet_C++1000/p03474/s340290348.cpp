#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int A, B;
   cin >> A >> B;
   string s;
   cin >> s;

   if(s[A] != '-') {
      cout << "No" << endl;
      return 0;
   }

   for(int i=0; i<A; i++) {
      if(s[i] < '0' || s[i] > '9') {
         cout << "No" << endl;
         return 0;
      }
   }

   for(int i=A+1; i<=A+B; i++) {
      if(s[i] < '0' || s[i] > '9') {
         cout << "No" << endl;
         return 0;
      }
   }
   cout << "Yes" << endl;
}