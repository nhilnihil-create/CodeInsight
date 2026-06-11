#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  string S; cin>>S;
  ll N=S.size();
  string newS="";
  rep(i,N){
    if(i<N-1&&S.substr(i,2)=="BC") {newS+='D'; i++;}
    else newS+=S[i];
  }
  S=newS;
  
  //cout<<S<<endl;
  
  vector<string> vec(0);
  
  string str="";
  for(auto cha:S){
    if(cha=='B'||cha=='C'){
      if(str!="") vec.push_back(str);
      str="";
    }
    else{
      str+=cha;
    }
  }
  vec.push_back(str);
  
  ll ans=0;
  for(auto str:vec){
    //cout<<str<<endl;
    ll n=str.size();
    ll count=0,sum=0;
    rep(i,n) if(str[i]=='D') {count++; sum+=i;}
    ans+=sum-count*(count-1)/2;
  }
  
  cout<<ans<<endl;
  return 0;
}