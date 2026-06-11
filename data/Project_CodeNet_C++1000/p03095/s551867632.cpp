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
  string s;
  cin >> n >> s;
  ll k=s.size();
  vl cnt(26);
  rep(i,k){
    rep(j,26){
      if(abc[j]==s[i]){
        cnt[j]++;
      }
    }
  }
  ll ans=1;
  rep(i,26){
    ans =ans*(1+cnt[i])%MOD;
  }
  cout << ans-1 << endl;
}