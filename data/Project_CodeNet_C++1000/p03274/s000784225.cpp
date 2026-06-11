#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
   int n, k; cin >> n >> k;
   vector<ll> c(n);
   bool pf = true;
   bool mf = true;
   int prd = 0;
   bool f = true;
   rep(i,n) {
      cin >>  c[i];

      if(c[i] >= 0) {
         mf = false;
      } else {
         pf = false;
      }

      if(c[i] >= 0 && f) {
         prd = i;
         f = false;
      }
   }

   ll ans = 0;
   if(pf) {
      ans = c[k-1];
   } else if(mf) {
      ans = abs(c[n - k]);
   } else {
      ll l = prd;
      ll r = l + k-1;
      /*cout << l << " " << r << endl;*/
      if(r >= n ) {
         ll diff = r - n;
         r -= diff + 1;
         l -= diff + 1;
         /*cout << diff + 1 << endl;*/
      }
      /*cout << l << " " << r << endl;*/
      ans = max(abs(c[r]), abs(c[l])) + 2*min(abs(c[r]), abs(c[l]));

      while(r >= prd && r >= 0 && l >= 0) {
         /*cout << l << " " << r << endl;*/
         ans = min(ans, max(abs(c[r]), abs(c[l])) + 2 * min(abs(c[r]), abs(c[l])));
         /*cout << max(abs(c[r]), abs(c[l])) + 2 * min(abs(c[r]), abs(c[l])) << endl;*/
         r--;
         l--;
      }
   }


   cout << ans << endl;
}

int main()
{
   solve1();
}