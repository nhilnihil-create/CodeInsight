#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 2e9;

void solveCase() {

   int n, x;
   cin >> n >> x;
   vector <int> v(n);
   for(auto &e: v) {
      cin >> e;
   }

   sort(v.begin(), v.end());


   int idx = 0;
   int ans = 0;
   while(x > 0 && idx < n) {
      if(x >= v[idx]) {
         x -= v[idx];
         ans++;
         if(idx + 1 == n && x > 0) {
            ans--;
         }
      } else {
         break;
      }
      idx++;
   }
   cout << ans << endl;
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
