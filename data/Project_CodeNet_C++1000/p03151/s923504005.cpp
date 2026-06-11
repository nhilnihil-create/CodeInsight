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
  ll n;
  cin >> n;
  vector<P> p(n);
  rep(i,n){
    cin >> p[i].first;
  }
  rep(i,n){
    cin >> p[i].second;
  }
  vl c(n);
  ll sum=0;
  ll sum2=0;
  ll cnt=0;
  rep(i,n){
    c[i]=p[i].first-p[i].second;
    sum +=c[i];
    if(c[i]<0){
      sum2+=c[i];
      cnt++;
    }
  }
  if(sum<0){
    cout << -1 << endl;
  }
  else{
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    ll i=0;
    while(sum2<0){
      sum2+=c[i];
      i++;
      cnt++;
    }
    cout << cnt << endl;
  }
}