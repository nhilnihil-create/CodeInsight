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
  string s;cin>>s;
  if(s.size()<26){
    rep(i,26){
      bool exist=false;
      rep(j,s.size()){
        if(s[j]==abc[i])exist=true;
      }
      if(!exist){
        cout<<s<<abc[i]<<endl;
        return 0;
      }
    }
  }
  ll k=-1;
  for(ll i=24;i>=0;i--){
    if(s[i]<s[i+1]){
      k=i;
      break;
    }
  }
  if(k==-1){
    cout<<k<<endl;
    return 0;
  }
  rep(i,k)cout<<s[i];
  char MIN='z';
  for(ll i=k+1;i<26;i++){
    if(s[i]>s[k])MIN=min(MIN,s[i]);
  }
  cout<<MIN<<endl;
}