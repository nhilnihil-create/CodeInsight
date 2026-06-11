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
  st S,T;
  cin >> S >> T;
  bool b=true;
  vl cnt1(26,0),cnt2(26,0);
  rep(i,(ll)S.size()){
    cnt1[S[i]-'a']++;
    cnt2[T[i]-'a']++;
  }
  sort(cnt1.begin(),cnt1.end());
  sort(cnt2.begin(),cnt2.end());
  rep(i,(ll)26){
    if(cnt1[i]!=cnt2[i]){
      b=false;
    }
  }
  if(b){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}