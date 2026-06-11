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
   int x; cin >> x;
   int ans = 1;
   for(int i = 2; i*i <= x; i++)
   {
      for(int j = 2; j <= 9; j++)
      {
         int k = ceil(pow(i, j));
         if(k <= x)
            ans = max(ans, k);
         else
            break;
      }
   }
   cout << ans << nl;
   return 0;
}
