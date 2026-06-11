#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main() 
{
  string S,T; cin>>S>>T;
  ll N=S.size(),M=T.size();
  for(int i=N-M;i>=0;i--)
  {
    rep(j,M)
    {
      if(S.at(i+j)!=T.at(j)&&S.at(i+j)!='?') goto OUT;
    }  
    rep(j,M)
    {
      S.at(i+j)=T.at(j);
    }
    rep(j,N)
    {
      if(S.at(j)=='?') S.at(j)='a';
    }  
    cout<<S<<endl; return 0;
    OUT:;
  }  
  cout<<"UNRESTORABLE"<<endl;
  return 0;
}
