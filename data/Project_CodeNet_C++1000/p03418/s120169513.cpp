#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 int main() {
   int N, K; cin >> N >> K;
   ll ans = 0;

   for (int b = 1; b <= N; b++) {
     int p = N / b, r = N % b;
     ans += p * max(0, b - K) + max(0, r - K + 1);
   }
   if (K == 0) ans -= N;
   
   cout << ans << endl;
 }
