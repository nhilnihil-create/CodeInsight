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

   int n, m, x; cin >> n >> m >> x;
   bool a[200] = {};
   rep(i,m)
   {
      int k; cin >> k;
      a[k] = true;
   }
   int sum1= 0, sum2 = 0;
   for(int i = x; i <= n; i++)
   {
      if(a[i])
         sum1++;
   }
   for(int i = 0; i <= x; i++)
   {
      if(a[i])
         sum2++;
   }
   cout << min(sum1, sum2) << nl;


   return 0;
}
