#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
   int n;
   cin >> n;
   vector<ll> v(n);
   ll ans = 0LL;
   rep(i,n){
      cin >> v[i];
      if (i == 0) ans+=abs(v[i]);
      else if (i == n-1) ans += abs(v[i]) + abs(v[i] - v[i-1]);
      else ans += abs(v[i] - v[i-1]);
   }
   //cout << ans << endl;
   for (int i = 0;i < n;i++){
      int tmp = ans;
      if (i == 0) {
         tmp -= abs(v[i]) + abs(v[i+1]-v[i]);
         tmp += abs(v[i+1]);
      }
      else if (i == n-1) {
         tmp -= abs(v[i]) + abs(v[i] - v[i-1]);
         tmp += abs(v[i-1]);
      }
      else {
         tmp -= abs(v[i] - v[i-1]) + abs(v[i+1]- v[i]);
         tmp += abs(v[i+1]-v[i-1]);
      }
      cout << tmp << endl;
   }

   return 0;
}

