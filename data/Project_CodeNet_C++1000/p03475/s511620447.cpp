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
  vl c(n-1),s(n-1),f(n-1);
  rep(i,n){
    cin >> c[i] >> s[i] >> f[i];
  }
  vl a(n);
  rep(i,n){
    ll t=0;
    FOR(j,i,n-1){
      if(t<s[j])
        t=s[j];
      else{
        while((t-s[j])%f[j]!=0){
          t++;
        }
      }
      t+=c[j];
    }
    a[i]=t;
  }
  rep(i,n){
    cout << a[i] << endl;
  }
}