#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 2e9;

void solveCase() {

   int a, b, c;
   cin >> a >> b >> c;
   int c_eat = min(c, a + b + 1);
   cout << c_eat + b << endl;

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
