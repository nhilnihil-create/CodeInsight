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
   int sum = 0;
   ll tmp = n;
   while(n)
   {
      sum += n%10;
      n/=10;
   }
   if(tmp%sum)
      cout << "No" << nl;
   else
      cout << "Yes" << nl;

   return 0;
}
