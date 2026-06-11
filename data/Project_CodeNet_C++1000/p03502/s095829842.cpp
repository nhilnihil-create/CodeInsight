#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int N;
   cin >> N;
   int f = 0;
   int n = N;

   while(n) {
      int dig = n % 10;
      f += dig;
      n /= 10;
   }

   if(N % f == 0) {
      cout << "Yes" << endl;
   } else {
      cout << "No" << endl;
   }
}