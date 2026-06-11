#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
   int N;
   cin >> N;

   string ans;

   while (N != 0) {
     int r = N % (-2);
     if (r < 0) r += 2;

     N = (N - r) / (-2);
     ans += (char)(r + '0');
   }

   reverse(ans.begin(), ans.end());
   if (ans== "") ans = "0";
   cout << ans << endl;
 }
