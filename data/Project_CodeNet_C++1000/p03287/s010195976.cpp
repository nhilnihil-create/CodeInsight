#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll n,m;
  cin >> n >> m;
  ll a[n+1];
  a[0]=0;
  rep(i,n)cin >> a[1+i];
  map<ll,ll> k;
  k[0]++;
  rep(i,n){
    a[i+1]=(a[i+1]+a[i])%m;
    k[a[i+1]]++;
  }
  ll ans=0;
  for(auto p: k){
    ll o=p.second;
    ans+=o*(o-1)/2;
  } 
  cout << ans << endl;
}   
