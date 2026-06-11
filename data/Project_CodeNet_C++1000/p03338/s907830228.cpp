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
   int n; cin >> n;
   string s; cin >> s;
   int ans = 0;
   for(int i =1; i < n-1; i++)
   {
      int tmp = 0;
      for(int j = 'a'; j <= 'z'; j++)
      {
         int co = 0;
         for(int h = 0; h < i; h++)
         {
            if(s[h] == j)
               co =1;
         }
         for(int m = i; m <n; m++)
         {
            if(s[m] == j)
            {
               co++;
               break;
            }

         }
         if(co>=2)
            tmp++;
      }
      ans = max(ans, tmp);
   }
   cout << ans << nl;
   return 0;
}
