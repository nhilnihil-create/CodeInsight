#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 2e9;

void solveCase() {

   int n;
   cin >> n;
   vector <ll> v(n);
   for(auto &e: v) {
      cin >> e;
   }
   map <ll, int> m;
   m[0] = 1;
   ll ans = 0;
   for(int i = 0; i < n; i++) {
      if(i > 0)
         v[i] += v[i - 1];
      ans += m[v[i]];
      m[v[i]]++;
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
