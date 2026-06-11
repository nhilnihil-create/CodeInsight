#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int d,n;
  cin>>d>>n;
  ll ans=1;
  while(d>0){
    ans*=100;
    d--;
  }
  int z=n;
  int y=z/100;
  ans*=(n+y);
  cout<<ans<<endl;
}