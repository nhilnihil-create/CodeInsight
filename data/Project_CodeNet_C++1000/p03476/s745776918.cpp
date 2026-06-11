#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
#define debug(...) 42


using ll = long long;

const int N = 1e5 + 5;
int ans[N];

void pre() {
   vector <bool> isPrime(N, true);

   isPrime[0] = isPrime[1] = false;
   for(int i = 2; i < N; i++) {
      if(isPrime[i] == true) {
         for(int j = i + i; j < N; j += i) {
            isPrime[j] = false;
         }
      }
   }
   for(int i = 3; i < N; i++) {
      if(isPrime[i] && isPrime[(i + 1) / 2]) {
         ans[i] = 1;
      }
      ans[i] += ans[i - 1];
   }
}
void solve() {
   int l, r;
   cin >> l >> r;
   cout << ans[r] - ans[l - 1] << endl;
} 

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   pre();
   int testcase = 1;
   cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   } 
   return 0;
}
