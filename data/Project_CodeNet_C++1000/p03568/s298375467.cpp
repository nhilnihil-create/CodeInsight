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
  ll n;cin>>n;
  vl t(n);
  rep(i,n)cin>>t[i];
  ll a=1,b=1;
  rep(i,n){
    if(t[i]%2==0){
      a*=3;
      b*=2;
    }
    else {
      a*=3;
    }
  }
  cout<<a-b<<endl;
}