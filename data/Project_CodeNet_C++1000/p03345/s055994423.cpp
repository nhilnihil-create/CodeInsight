#include<iostream>
using namespace std;
using ll=long long;
int main(){

  ll A,B,C;
  cin>>A>>B>>C;
  ll K;
  cin>>K;
  int ans=0;
  if(K%2==0)cout<<A-B;
  else cout<<B-A;
  return 0;
}