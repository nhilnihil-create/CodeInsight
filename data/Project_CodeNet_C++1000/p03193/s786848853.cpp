#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N, H, W;

   cin >> N >> H >> W;

   int ans = 0;
   for (int i = 0; i < N; i++) {
     int h, w;
     cin >> h >> w;
     if (h >= H && w >= W) ans++;
   }

   cout << ans << endl;
 }
