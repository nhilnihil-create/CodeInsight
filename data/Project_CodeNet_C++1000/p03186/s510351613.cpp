#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
  ll a,b,c;
  cin>>a>>b>>c;
  if(a + b >= c){
    cout<<b+c<<"\n";
  }else{
    cout<<a + 2*b + 1<<"\n";
  }
  return 0;
}