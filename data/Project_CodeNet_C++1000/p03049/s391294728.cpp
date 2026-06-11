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
  string a;
  ll cnt=0;
  ll A=0,B=0,both=0;
  rep(i,n){
    cin >> a;
    ll k=a.size();
    rep(i,k-1){
      if(a[i]=='A'&&a[i+1]=='B'){
        cnt++;
      }
    }
    if(a[0]=='B'&&a[k-1]=='A'){
      both++;
    }
    else if(a[k-1]=='A'){
      A++;
    }
    else if(a[0]=='B'){
      B++;
    }
  }
  //cout << A << " " << B << " " << both << " " << cnt << endl;
  ll ans=cnt;
  ans+=min(A,B);
  ans+=both;
  if(max(A,B)==0&&both!=0){
    ans--;
  }
  cout << ans << endl;
}