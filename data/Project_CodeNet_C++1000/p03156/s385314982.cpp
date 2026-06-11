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
  ll n,a,b;
  cin >> n >> a >> b;
  vl p(n);
  ll cnt1=0,cnt2=0,cnt3=0;
  rep(i,n){
    cin >> p[i];
    if(p[i]<=a){
      cnt1++;
    }
    else if(p[i]>=b+1){
      cnt3++;
    }
    else
      cnt2++;
  }
  cout << min(cnt1,min(cnt2,cnt3)) << endl;
}