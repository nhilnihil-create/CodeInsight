#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i, k , n) for(int i = k; i <= n; i++)
typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

   int a, b, k; cin >> a >> b >> k;
   if(b-a +1 <= 2*k)
   {
      REP(i, a, b)
         cout << i << nl;
      return 0;
   }
   REP(i,a, a+k-1)
      cout << i << nl;
   for(int i = b-k+1; i <= b; i++)
      cout << i << nl;


   return 0;
}
