#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N, K;
   cin >> N >> K;
   vector<ll> v(K);
  for(int i = 1; i <= N; i++) { 
      v[i % K] += 1;  
   }
    ll ans = 0;
   for(int a = 0; a < K; a++) {
       int b = (K - a) % K;
       int c = (K - b) % K;
       if((c + a) % K != 0) continue;
       ans += v[a] * v[b] * v[c];
   }

   cout << ans;
    return 0;

}