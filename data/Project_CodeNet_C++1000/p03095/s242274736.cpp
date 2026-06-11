#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int mod = 1e9 + 7;
vector<int> cnt(26);

ll get(int idx, ll cur) {
   if(idx == 26) {
      return cur % mod;
   }
   ll ans = get(idx + 1, cur);
   ans += get(idx + 1, (cur * cnt[idx]) % mod);
   return ans % mod;
}

void solveCase() {

   int n;
   cin >> n;
   string s;
   cin >> s;
   for(auto &e: s) {
      cnt[e - 'a']++;
   }

   cout << (get(0, 1) + mod - 1) % mod << endl;
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
