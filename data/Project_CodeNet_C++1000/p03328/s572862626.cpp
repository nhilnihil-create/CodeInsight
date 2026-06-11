#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
  ll a,b,c,sum=0;
  cin>>a>>b;
  c = b - a;
  for(int i=1;i<c;i++){
    sum += i;
  }
  cout<<sum-a<<"\n";
  return(0);
}