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
  string t,T;
  cin >> n;
  ll a=0,b=n;
  cout << a << endl;
  cin >> t;
  while(t!="Vacant"){
    ll m=(a+b)/2;
    cout << m << endl;
    cin >> T;
    if(((T!=t)&&(a-m)%2==0)||((T==t)&&(a-m)%2!=0)){
      b=a;
    }
    a=m;
    t=T;
  }
}
