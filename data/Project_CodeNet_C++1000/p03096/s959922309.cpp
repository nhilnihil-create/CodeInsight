#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
const ll N = 200500;
const ll m = (ll)1e9 + 7;
ll n,c[N],dp[N];
vector <ll> pos[N];

ll add(ll a , ll b) {
   return ((a % m) + (b % m)) % m;
}

ll f(ll curr) {
   if (curr > n) return 1;
   ll &sol = dp[curr];
   if (sol != -1) return sol;
   auto it = upper_bound(pos[c[curr]].begin() , pos[c[curr]].end() , curr);
   if (it == pos[c[curr]].end()) {
      sol = f(curr + 1);
   } else {
      if (abs((*it) - curr) == 1) {
         sol = f(curr + 1);
      } else {
         sol = add(f(curr + 1) , f(*it));
      }
   }
   return sol;
}

int main() {
   scanf("%lld" , &n);
   for (ll i = 1 ; i <= n ; i++) {
      scanf("%lld" , &c[i]);
      pos[c[i]].push_back(i);
   }
   memset (dp , -1 , sizeof dp);
   printf("%lld\n" , f(1));
}
