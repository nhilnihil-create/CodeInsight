#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n;
  cin >> n;
  ll ans=INF;
  FOR(i,1,n){
    ll a=i,b=n-i;
    ll cnt=0;
    while(a!=0){
      cnt+=a%10;
      a/=10;
    }
    while(b!=0){
      cnt+=b%10;
      b/=10;
    }
    ans=min(ans,cnt);
  }
  cout << ans << endl;
}