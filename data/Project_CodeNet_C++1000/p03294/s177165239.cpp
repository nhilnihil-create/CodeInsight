#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   long long ans = 0;
   while(n--) {
       int foo;
       cin >> foo;
       ans += --foo;
   }
   cout << ans << endl;
}