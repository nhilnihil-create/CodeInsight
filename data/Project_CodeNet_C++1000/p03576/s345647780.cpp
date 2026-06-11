#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n,k;
  cin >> n >> k;
  vector<P> p(n);
  rep(i,n){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(),p.end());
  vl y(n);
  ll ans=4*INF+1;
  rep(i,n-k+1){
    FOR(j,i+k-1,n){
      ll x=p[j].first-p[i].first;
      rep(h,n){
        y[h]=INF;
      }
      rep(h,j-i+1){
        y[h]=p[h+i].second;
      }
      sort(y.begin(),y.end());
      ll ymin=INF;
      rep(h,j-i-k+2){
        ymin=min(ymin,y[h+k-1]-y[h]);
      }
      ans=min(ans,x*ymin);
    }
  }
  cout << ans << endl;
}