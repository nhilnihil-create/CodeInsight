#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a=0;
  for(int64_t i=1;i*i<=m;i++)
    if(m%i==0)
      a=max({a,(i<=m/n?(int)i:0),(m/i<=m/n?m/(int)i:0)});
  cout<<a<<endl;
}