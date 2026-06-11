#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX = 510000;
ll gcd(ll a, ll b){
    if (a % b == 0)
    {  return(b);}
    else{return(gcd(b, a % b));}
}
ll lcm(ll a, ll b)
{return a * b / gcd(a, b);}

int main(){
  int n;
  cin >>n;
  vector<ll>x(n);
  vector<ll>p(n);
  rep(i,n){cin>>x[i];p[i]=x[i];}
  sort(p.begin(),p.end());
  rep(i,n){
  	if(x[i]>=p[n/2]){cout<<p[(n/2)-1]<<endl;}
    else{cout<<p[n/2]<<endl;}
  }
}