#include<bits/stdc++.h>
using namespace std;
#define outc cout
#define int long long
signed main(){
  int a,g[1000000];
  int b=0,c=1,d;
  cin>>a;
  for(int i=0;i<a*3;i++){
    cin>>g[i];
  }
  for(int i=1;i<a;i++){
    if(g[i-1]==g[i]) b++,g[i]=-1;
  }
  cout<<b<<"\n";
  }
