#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   ll A, B, C;

   cin >> A >> B >> C;

   ll ans;

   if (A + B + 1 >= C) ans = B + C;

   else ans = (ll)(A + 2 * B + 1);

   cout << ans << endl;
   }
