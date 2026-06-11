#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i, k , n) for(int i = k; i <= n; i++)
typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

   int a, b, c, x;
   cin >> a >> b >> c >> x;
   int ans = 0;
   REP(i, 0, a)
   {
      REP(j, 0, b)
      {
         REP(k,0,c)
         {
            if(i*500 + j*100 + k*50 == x)
               ans++;
         }
      }
   }
   cout << ans << nl;

   return 0;
}
