
#include <bits/stdc++.h>
using namespace std;

int main(void) {
   long A,B,C;
   cin>>A>>B>>C;
   long ans = 0;
   if (C>=B) {
      ans += 2 * B;
      C -= B;
      if (C > A) ans += A+1;
      else ans += C;
   } else {
      ans = B+C;
   }
   cout<<ans<<endl;

   return 0;
}