#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,d=0;
  int c[100]={};
  for(int i=0;i<3;i++){
    cin>>a>>b;
    c[a]++;
    c[b]++;
  }
  for(int i=0;i<5;i++){
    if(c[i]>=3) d=1;
  }
  if(d==0) cout<<"YES";
  else cout<<"NO";
  cout<<"\n";
}