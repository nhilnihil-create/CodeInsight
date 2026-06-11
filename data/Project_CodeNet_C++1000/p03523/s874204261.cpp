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
  rep(i,16){
    string t="AKIHABARA";  
    if(i&(1<<0))t[0]='#';
    if(i&(1<<1))t[4]='#';
    if(i&(1<<2))t[6]='#';
    if(i&(1<<3))t[8]='#';
    string ans="";
    rep(j,t.size()){
      if(t[j]!='#')ans+=t[j];
    }
    //cout<<ans<<endl;
    if(ans==s){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
  