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
  map<int,int> D;
  rep(i,N)
  {
    int d; cin>>d;
    if(D.count(d)) {D.at(d)++; continue;}
    D[d]=1;
  }
  int M; cin>>M;
  rep(i,M)
  {
    int T; cin>>T;
    if(!(D.count(T))) {cout<<"NO"<<endl; return 0;}
    if(D.at(T)==0) {cout<<"NO"<<endl; return 0;}
    D.at(T)--;
  }
  cout<<"YES"<<endl;
  return 0;
}
