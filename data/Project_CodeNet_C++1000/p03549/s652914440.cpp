#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Rev(a) reverse(a.begin(), a.end())
typedef long long ll;
const ll MOD = 1e9+7;

/*ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}*/
/*ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}*/

/*ll lcm(ll a, ll b){
  ll g = gcd(a, b);
  b /= g;
  a *= b;
  return a;
}*/

/*int dfs(vector<int> &T, vector<int> &C, int i, int sum, int g, int count){
   
}*/

int main(){
  int n, m;
  cin >> n >> m;
  ll ans= (n-m)*100+1900*m;
  int g=1;
  rep(i, m) g *= 2;
  cout << ans*g << endl;

}

