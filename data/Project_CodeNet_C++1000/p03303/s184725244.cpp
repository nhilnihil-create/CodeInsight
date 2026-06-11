#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  int c,d=0;
  cin>>a>>c;
  for(int i=0;i<a.size();i++){
    if(d==c) d=0;
    if(d==0) cout<<a[i];
    d++;
   // cout<<d<<" "<<i<<" "<<a.size()<<"\n";
  }
  cout<<"\n";
}