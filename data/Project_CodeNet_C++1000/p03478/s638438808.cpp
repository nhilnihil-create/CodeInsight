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
   int n, a, b;
   cin >> n >> a >> b;
   int sum = 0;
   for(int i = 1; i <= n; i++)
   {
      int x = i;
      int tmp =0;
      while(x)
      {
         tmp += x%10;
         x /= 10;
      }
      if(tmp >= a && tmp <= b)
         sum += i;
   }
   cout << sum << nl;
   return 0;
}
