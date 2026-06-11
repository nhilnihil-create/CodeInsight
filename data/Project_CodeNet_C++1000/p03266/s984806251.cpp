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
   
   if(K % 2 == 0) {
       ll a = N / K;
       ll b = (N + K / 2) / K;
       ans = (a * a * a) + (b * b * b); 
   }else {
       ll c = N / K;
       ans = c * c * c;
       
   }

   cout << ans;
    return 0;

}