#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n;
  cin >> n;
  vl a(n),b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  ll cnt=0;
  ll num=0,num1=0;
  rep(i,n){
    cnt+=b[i]-a[i];
    num+=max((ll)0,(b[i]-a[i]+1)/2);
    num1+=max((ll)0,(a[i]-b[i]));
  }
  if(cnt>=0&&cnt>=num&&cnt>=num1){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
