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
  vl b(n),c(n);
  ll ans=0;
  rep(i,n){
    cin >> b[i];
    b[i]--;
  }
  rep(i,n){
    for(ll j=n-i-1;j>=0;j--){
      if(b[j]==j){
        c[n-1-i]=b[j]+1;
        FOR(k,j,n-1){
          b[k]=b[k+1];
        }
        break;
      }
      else if(j==0){
        ans=1;
      }
    }
  }
  if(ans){
    cout << -1 << endl;
  }
  else{
    rep(i,n){
      cout << c[i] << endl;
    }
  }
}