#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main(){
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  ll num = lcm(n, m);
  ll a = num/m;
  ll b = num/n;
  ll cntA = 0;
  ll cntB = 0;
  bool isok = true;
  while(cntA < n){
    if(s[cntA] != t[cntB]){
      isok = false;
      break;
    }
    cntA += a;
    cntB += b;
  }
  if(isok) cout << num << endl;
  else cout << -1 << endl;
  return 0;
}