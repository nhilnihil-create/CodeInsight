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

   int n, m; cin >> n >> m;
   int ans = 1e9;
   rep(i, n)
   {
      int a; cin >> a;
      ans = min(a, ans);
      m-= a;
   }
   cout << n + m/ans << nl;

   return 0;
}
