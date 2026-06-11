#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 2e9;

void solveCase() {

   int n, a, b;
   cin >> n >> a >> b;

   int d = abs(a - b);

   if(d % 2 == 0) {
      cout << "Alice" << endl;
   } else {
      cout << "Borys" << endl;
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
