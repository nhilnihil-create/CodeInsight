#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0;i < (n);i++)
using namespace std;
typedef long long ll;

int main() {
   int n,k,ans=1;
   cin >> n >> k;
   rep(i, n) {
      if(ans*2 <= ans+k) {
         ans *= 2;
      }else {
         ans += k;
      }
   }
   cout << ans << endl;
   return 0;
}