#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N;
   string S;

   cin >> N >> S;

   vector<int> count(26);

   for (int i = 0; i < N; i++) {
     count.at((int)(S.at(i) - 'a'))++;
   }

   ll ans = 1;
   int div = 1000000007;

   for (int i = 0; i < 26; i++) {
     ans *= count.at(i) + 1;
     ans %= div;
   }

   cout << ans - 1 << endl;
 }
