#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
   int N;
   cin >> N;

   vector<int> A(N), Ar(N);
   double ave = 0.0;

   rep(i, 0, N) {
     cin >> A.at(i);
     Ar.at(i) = A.at(i) - i - 1;
   }

   sort(Ar.begin(), Ar.end());

   int b = Ar.at(N / 2);

   ll ans = 0;
   rep(i, 0, N) {
     ans += abs(b - Ar.at(i));
   }
   cout << ans << endl;
 }
