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
   ll n; cin >> n;
   int a[n];
   for(int i = 0; i <n; i++)
      cin >> a[i];
   int ans = 0;
   while(1)
   {
      for(int i = 0; i < n; i++)
      {
         if(a[i]%2)
         {
            cout << ans << nl;
            return 0;
         }
         a[i]/=2;
      }
      ans++;
   }
   return 0;
}
