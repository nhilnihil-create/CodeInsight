#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0;i < (n);i++)
using namespace std;
typedef long long ll;

int main() {
   ll D, G, ans = 1000000;
   cin >> D >> G;
   ll p[D], c[D];
   rep(i, D) cin >> p[i] >> c[i];
   for(ll bit = 0;bit < (1 << D);bit++) {
      ll sum = 0, cnt = 0;
      rep(i, D) {
         if(bit & (1 << i)) {
            sum += 100 * (i + 1) * p[i] + c[i];
            cnt += p[i];
         }
      }
      if(sum >= G) {
         ans = min(ans, cnt);
      }else {
         for(ll i = D-1;i >= 0;i--) {
            if(bit & (1 << i)) continue;
            for(ll j = 0;j < p[i];j++) {
               if(sum >= G) break;
               sum += 100 *(i + 1);
               cnt++;
            }
           
         }
         ans = min(ans, cnt);
      }

   }
   cout << ans << endl;
}