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
   vector<int> v;
   rep(i,n)
   {
      int x; cin >> x;
      v.push_back(x);
   }
   sort(rall(v));
   int Alice = 0, Bob = 0;
   rep(i, n)
   {
      if(i&1)
         Alice+=v[i];
      else
         Bob += v[i];
   }
   cout << Bob - Alice << nl;
   return 0;
}
