#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N,M; cin>>N>>M;
  ll T=(N-M)*100+1900*M;
  cout<<T*pow(2,M)<<endl;
  return 0;
}