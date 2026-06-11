#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;

int sum(int x) {
   if(x < 10) return x;
   return x % 10 + sum(x / 10);
}

void solveCase() {
   int n;
   cin >> n;

   vector <int> v(n);
   for(auto &e: v) {
      cin >> e;
   }

   vector <int> cntArr;
   int cur = v[0];
   int cnt = 1;
   for(int i = 1; i < n; i++) {
      if(v[i] == cur) {
         cnt++;
      } else {
         cntArr.push_back(cnt);
         cnt = 1;
         cur = v[i];
      }
   }
   cntArr.push_back(cnt);
   int ans = 0;
   for(auto x: cntArr) {
      ans += x / 2;
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