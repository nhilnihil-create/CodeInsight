#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Reve(a) reverse(a.begin(), a.end())
typedef long long ll;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}
ll lcm(ll a, ll b){
  ll g = gcd(a, b);
  b /= g;
  a *= b;
  return a;
}

int main(){
  ll n, m, i=0, j=0;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  ll ans = lcm(n, m); 
  ll m1 = ans/n;
  ll m2 = ans/m;
  ll g = lcm(m1, m2);
  while(i<n){
    if(s.at(i)!=t.at(j)) ans = -1;
    i += m2;
    j += m1;
  }  
  cout << ans << endl;

}