#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  vector<ll> A(N+1,0);
  rep(i,N)
  {
    cin>>A.at(i+1);
  }
  /*rep(i,N+1)
  {
    if(i!=0) {cout<<" ";}
    cout<<A.at(i);
    if(i==N) {cout<<endl;}
  }*/ 
  ll all=0;
  rep(i,N+1)
  {
    if(i==N) {all+=abs(A.at(0)-A.at(N)); continue;}
    all+=abs(A.at(i+1)-A.at(i));
  }
  //cout<<all<<endl;
  for(ll i=1;i<=N;i++)
  {
    if(i==N) 
    {
      cout<<all-(abs(A.at(N)-A.at(N-1))+abs(A.at(N)-A.at(0)))+abs(A.at(0)-A.at(N-1))<<endl;
      continue;
    }
    cout<<all-(abs(A.at(i)-A.at(i-1))+abs(A.at(i)-A.at(i+1)))+abs(A.at(i-1)-A.at(i+1))<<endl;
  }
          
  
  return 0;
}