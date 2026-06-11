#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;





int main() 
{
  ll N; cin>>N;
  ll A,B,C,D,E; cin>>A>>B>>C>>D>>E;
  ll hoge=min(A,min(B,min(C,min(D,E))));
  ll ans=4+N/hoge;
  if(N%hoge!=0) {ans++;}
  cout<<ans<<endl;
  return 0;
}
