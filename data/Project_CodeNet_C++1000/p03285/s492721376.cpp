#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  
  for(int i=0; i<=n/4; ++i) for(int j=0; j<=n/7; ++j) if(i*4+j*7==n) return cout<<"Yes\n",0;
  cout<<"No\n";
  return 0;
}