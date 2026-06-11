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
  int n,k;
  cin >> n >> k;
  int a[n];
  int b[n];
  rep(i,n)cin >> a[i] >> b[i];
  int c[n];
  int d[n];
  rep(i,n){
    c[i]=a[i];
    d[i]=b[i];
  }
  sort(c,c+n);
  sort(d,d+n);
  ll ans=4000000000000000001;
  rep(i,n){
    rep(j,i){
      rep(o,n){
        rep(p,o){
          //if(i==j||o==p)continue;
          ll minx=(ll)c[j],maxx=(ll)c[i],miny=(ll)d[p],maxy=(ll)d[o];
          int cnt=0;
          rep(i,n){
            if(a[i]>=minx&&a[i]<=maxx&&b[i]<=maxy&&b[i]>=miny)cnt++;
          }
          if(cnt>=k){
            ans=min(ans,(maxx-minx)*(maxy-miny));
          }
        }
      }
    }
  }
  cout << ans << endl;
}   
