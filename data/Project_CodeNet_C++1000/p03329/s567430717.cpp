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
  ll N; cin>>N;
  vector<ll> table(10000000,INF);
  table.at(0)=0;
  rep(i,N)
  {
    chmin(table.at(i+1),table.at(i)+1);
    for(int j=1;j<=7;j++)
    {
      chmin(table.at(i+pow(6,j)),table.at(i)+1);
    } 
    for(int j=1;j<=6;j++)
    {
      chmin(table.at(i+pow(9,j)),table.at(i)+1);
    } 
  }
  cout<<table.at(N)<<endl;
  /*
  rep(i,20)
  {
    if(i!=0) cout<<" ";
    cout<<table.at(i);
  }
  cout<<endl;
  */
  return 0;
}