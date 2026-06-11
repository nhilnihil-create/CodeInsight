#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll n;
  ll m;
  cin >> n >> m;
  ll x[n],y[n],z[n];
  rep(i,n)cin >> x[i] >> y[i] >> z[i];
  ll ans=0;
  rep(i,8){
    ll aans=0;
    ll k[n];
    rep(j,n){
      ll p=0;
      if(i&(1<<0)){
        p+=x[j];
      }
      else p-=x[j];
      if(i&(1<<1)){
        p+=y[j];
      }
      else p-=y[j];
      if(i&(1<<2)){
        p+=z[j];
      }
      else p-=z[j];
      k[j]=p;
    }
    sort(k,k+n);
    rep(v,m)aans+=k[n-1-v];
    ans=max(ans,aans);
  }
  cout << ans << endl;
}  
