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

   int ans = 123456;
   for(int i = 1; i < n; i++) {
      int a = i;
      int b = n - a;
      int s = sum(a) + sum(b);
      if(s < ans) ans = s;
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