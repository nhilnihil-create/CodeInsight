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
  map<ll,ll>M;
  ll two=0,one=0;
  rep(i,3){
    ll a,b;cin>>a>>b;
    M[a]++;M[b]++;
  }
  for(auto p:M){
    if(p.second==2)two++;
    if(p.second==1)one++;
  }
  if(one==2&two==2)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}