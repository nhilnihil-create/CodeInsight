#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  int N; cin>>N;
  vector<int> sa(N);
  rep(i,N)
  {
    cin>>sa.at(i);
  }
  rep(i,N)
  {
    ll b; cin>>b;
    sa.at(i)-=b;
  }
  /*
  rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    cout<<sa.at(i);
  }
  cout<<endl;
  */
  sort(sa.begin(),sa.end());
  ll hoge=0;
  int ans=0;
  rep(i,N)
  {
    if(sa.at(i)>=0) {break;}
    hoge+=sa.at(i);
    ans++;
  }
  hoge*=-1;
  reverse(sa.begin(),sa.end());
  rep(i,N)
  {
    if(hoge<=0) {break;}
    hoge-=sa.at(i);
    ans++;
  }
  if(hoge>0) {cout<<-1<<endl; return 0;}
  cout<<ans<<endl;
  return 0;
}