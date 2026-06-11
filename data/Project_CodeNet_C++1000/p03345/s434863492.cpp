#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 2e9;

void solveCase() {

   ll a, b, c, k;
   cin >> a >> b >> c >> k;
   if(k % 2 == 0) {
      cout << a - b << endl;
   } else {
      cout << b - a << endl;
   }
}


int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solveCase();
   }
 
   return 0;
}
