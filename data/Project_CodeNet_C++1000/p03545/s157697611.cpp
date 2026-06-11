#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0;i < (n);i++)
using namespace std;
typedef long long ll;

int main() {
   char n[4];
   cin >> n;
   
   for(int bit = 0;bit < (1 << 3);bit++) {
      ll a = n[0] - '0';
      rep(i, 3) {
         if(bit & (1<<i)) {
            a += n[i+1]- '0';
         }else {
            a -= n[i+1] - '0';
         }
         
      }
      if(a == 7) {
         cout << n[0] - '0';
         rep(i,3) {
            if(bit & (1<<i)) {
               cout << "+";
               cout << n[i+1] - '0';
            }else {
               cout << "-";
               cout << n[i+1] - '0';
            }
         }
         cout << "=" << 7 << endl;
         return 0;
      }
   }
}
