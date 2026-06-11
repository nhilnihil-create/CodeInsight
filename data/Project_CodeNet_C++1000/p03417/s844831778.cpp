#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N,M; cin>>N>>M;
  if(N==1&&M==1) {cout<<1<<endl; return 0;}
  cout<<abs((N-2)*(M-2))<<endl;
  return 0;
}