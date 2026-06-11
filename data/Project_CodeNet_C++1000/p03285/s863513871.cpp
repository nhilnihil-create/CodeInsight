#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  if(N%7==0) {
cout<<"Yes"<<endl;
    return 0;
  }
  ll money=N/7*7;
  
  for(ll i=0;i<N/7+1;i++) {
  while(money<N) {
money+=4;
  }
  if(money==N) {
cout<<"Yes"<<endl;
  return 0;
  }
    money-=7;
  }

  
  cout<<"No"<<endl;
}
  
  
  
  
