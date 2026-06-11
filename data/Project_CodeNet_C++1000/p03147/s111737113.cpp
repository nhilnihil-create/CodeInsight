#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;





int main() 
{
  ll N; cin>>N;
  vector<ll> h(N);
  ll maxh=0;
  rep(i,N)
  {
    cin>>h.at(i);
    maxh=max(maxh,h.at(i));
  }
  /*rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    cout<<h.at(i);
    if(i==N-1) {cout<<endl;}
  }*/
  ll count=0;
  for(ll i=0;maxh>0;i++)
  {
    rep(j,N)
    {
      if(j==N-1&&h.at(N-1)>0) {count++; h.at(N-1)--; /*cout<<h.at(j)<<" "<<count<<endl;*/ continue;}
      if(h.at(j)>0&&h.at(j+1)==0) {count++;}  
      if(h.at(j)>0) {h.at(j)--;}
      //cout<<h.at(j)<<" "<<count<<endl;
    }
    maxh--;
  }
  cout<<count<<endl;
  return 0;
}
