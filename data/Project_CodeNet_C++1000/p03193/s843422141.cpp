#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, th, tw, h, w, ans=0;
int main() {
   cin >> n >> th >> tw;
   while (n--) {
       cin >> h >> w;
       if (th<=h&&tw<=w) ans++;
   }
   cout << ans;
}