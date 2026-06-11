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
#define ROF(i,a,b) for(ll i=b-1;i>=a;i--)
#define per(i,b) ROF(i,0,b)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

ll gcd(ll x,ll y){
  if(x%y==0){
    return y;
  }
  else{
    return gcd(y,x%y);
  }
}

int main(){
  ll q;
  cin >> q;
  rep(t,q){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a<b){
      cout << "No" << endl;
    }
    else if(b>d){
      cout << "No" << endl;
    }
    else if(c>=b){
      cout << "Yes" << endl;
    }
    else{
      ll x=gcd(b,d);
      a%=x;
      if(a==0){
        if(b-x>c){
          cout << "No" << endl;
        }
        else{
          cout << "Yes" << endl;
        }
      }
      else{
        if(b-x+a>c){
          cout << "No" << endl;
        }
        else{
          cout << "Yes" << endl;
        }
      }
    }
  }
}