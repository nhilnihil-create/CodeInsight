#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t;
  cin>>n>>t;
  int c=0;
  for(int i=0;i<n;i++){
    int ci,ti;
    cin>>ci>>ti;
    if(ti<=t)
      c=(c==0?ci:min(c,ci));
  }
  if(c==0)
    cout<<"TLE"<<endl;
  else
    cout<<c<<endl;
}