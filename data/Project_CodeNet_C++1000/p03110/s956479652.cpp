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
  vector<pair<double,string>> a(n);
  rep(i,n){
    cin >> a[i].first >> a[i].second;
  }
  double sum=0;
  rep(i,n){
    if(a[i].second=="BTC"){
      sum +=380000*a[i].first;
    }
    else
      sum +=a[i].first;
  }
  cout << fixed << setprecision(10) << sum << endl;
}