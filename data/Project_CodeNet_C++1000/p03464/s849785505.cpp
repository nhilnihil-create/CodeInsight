//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll k;cin>>k;
  vl a(k);
  rep(i,k)cin>>a[i];
  reverse(a.begin(),a.end());
  if(a[0]!=2){
    cout<<-1<<endl;
    return 0;
  }
  ll n=2;
  ll MAX=2;
  ll MIN=2;
  rep(i,k){
    MIN=(MIN+a[i]-1)/a[i]*a[i];
    MAX=(MAX+a[i]-1)/a[i]*a[i]+a[i]-1;
    if(i!=k-1){
      MIN=(MIN+a[i+1]-1)/a[i+1]*a[i+1];
      MAX=MAX/a[i+1]*a[i+1];
    }
    if(MIN>MAX){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<MIN<<" "<<MAX<<endl;
}
  
  
  