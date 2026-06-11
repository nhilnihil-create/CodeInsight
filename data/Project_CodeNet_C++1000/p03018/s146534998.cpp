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
  rep(i,s.size()-1){
    if(s[i]=='B'&&s[i+1]=='C'){
      s=s.replace(i,2,"D");
      i--;
    }
  }
  ll count=0;
  ll part=0;
  rep(i,s.size()){
    if(s[i]=='A')part++;
    else if(s[i]=='D')count+=part;
    else part=0;
  }
  cout<<count<<endl;
}
  
  