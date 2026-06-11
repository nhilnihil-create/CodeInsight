#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  string ans="";
  ll N; cin>>N;
  if(N==0) {cout<<"0"<<endl; return 0;}
  while(N!=0){
    //cout<<N<<endl;
    ll amari=N%(-2);
    N/=(-2);
    if(amari==-1){
      N++;
      amari=1;
    }
    ans+=(char)(amari+'0');
  }
  
  reverse(ans.begin(),ans.end());
  
  cout<<ans<<endl;
  return 0;
}