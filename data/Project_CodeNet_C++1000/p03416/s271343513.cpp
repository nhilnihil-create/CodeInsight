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

   int a, b; cin >> a >> b;
   int ans = 0;
   REP(i, a, b)
   {
      int tmp = i;
      int res = 0;
      while(tmp)
      {
         res = res*10 + tmp%10;
         tmp /=10;
      }
      if(res== i)
         ans++;

   }
   cout << ans << nl;
   return 0;
}
