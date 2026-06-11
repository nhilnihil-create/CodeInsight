#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;

int main(){
   ll n; cin >> n;
   vector<tuple<ll,ll,ll>> c;
   rep(i,n){
      ll a,b; cin >> a >> b;
      c.emplace_back(a + b, a, b);
   }
   sort(begin(c), end(c), greater<tuple<ll,ll,ll>>());

   ll ans = 0;
   rep(i,n){
      if(i % 2 == 0)ans += get<1>(c[i]);
      else ans -= get<2>(c[i]);
   }
   cout << ans << endl;
}
