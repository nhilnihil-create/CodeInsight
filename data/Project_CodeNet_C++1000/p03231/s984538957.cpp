#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;

ll gcd(ll a, ll b){
  if (a%b == 0)return(b);
  else return(gcd(b, a%b));
}

ll lcm(ll a, ll b){
   return a * b / gcd(a, b);
}

int main(){

  ll n,m;cin>>n>>m;
  string s,t;cin>>s>>t;
  ll l=lcm(n,m);

  ll a=l/n,b=l/m;
  for(ll i=0,j=0;i<n&&j<m;){
    if(i*a>j*b)j++;
    else if(i*a==j*b){
      if(s[i]!=t[j]){
        out(-1);
        return 0;
      }
      i++;
      j++;
    }
    else i++;
  }
  out(l);


  return 0;
}
