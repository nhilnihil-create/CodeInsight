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
  string s;
  cin >> s;
  vl a(n+2*k+5,0);
  ll j=0;
  if(s[0]=='0'){
    j++;
  }
  a[j]++;
  FOR(i,1,n){
    if(s[i]==s[i-1]){
      a[j]++;
    }
    else{
      j++;
      a[j]++;
    }
  }
  ll t=0;
  rep(i,2*k+1){
    t +=a[i];
  }
  ll ans=t;
  for(ll i=0;2*k+i<n;i+=2){
    t -=a[i]+a[i+1];
    t +=a[2*k+1+i]+a[2*k+2+i];
    ans=max(ans,t);
  }
  cout << ans << endl;
}