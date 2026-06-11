#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

   int a, b, c, x;
   cin >> a >> b >> c >> x;
   int ans = 0;
   for(int i = 0; i <= a; i++)
   {
      for(int j = 0; j<= b; j++)
      {
         for(int k = 0; k <= c; k++)
         {
            if(i*500 + j*100 + k*50 == x)
               ans++;
         }
      }
   }
   cout << ans << nl;

   return 0;
}
