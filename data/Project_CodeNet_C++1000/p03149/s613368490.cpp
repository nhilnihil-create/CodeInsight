#include<bits/stdc++.h>
using namespace std;
int main(){
  string q;
  int a=0,b=0,c=0,d=0;
  for(int i=0;i<4;i++){
    cin>>q;
    if(q=="1") a=1;
    if(q=="4") b=1;
    if(q=="7") c=1;
    if(q=="9") d=1;
  }
  if(a+b+c+d==4) cout<<"YES";
  else cout<<"NO";
  cout<<"\n";
}