#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int l=0;
  cout<<0<<endl;
  string cl;
  cin>>cl;
  if(cl=="Vacant")
    return 0;
  int r=n-1;
  cout<<n-1<<endl;
  string cr;
  cin>>cr;
  if(cr=="Vacant")
    return 0;
  while(1){
    int h=(l+r)/2;
    cout<<h<<endl;
    string ch;
    cin>>ch;
    if(ch=="Vacant")
      return 0;
    if(((h-l)%2==0)^(cl==ch)){
      r=h;
      cr=ch;
    }else{
      l=h;
      cl=ch;
    }
  }
}