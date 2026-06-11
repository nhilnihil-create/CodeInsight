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
   int n; cin >>n;
   ll l1 = 2, l2= 1;
   ll ans;
   if(n == 0)
   {
      cout << 2 << nl;
      return 0;
   }
   if(n==1)
   {
      cout << 1 << nl;
      return 0;
   }
   for(int i = 2; i <= n; i++ )
   {
      ans = l2 + l1;
      l1 = l2;
      l2 = ans;
   }
   cout << ans << nl;

   return 0;
}
