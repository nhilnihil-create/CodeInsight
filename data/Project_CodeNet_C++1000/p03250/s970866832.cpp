#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ma=0;
  if(a>=b&&a>=c){
    cout<<a*10+b+c<<endl;
  }
  else if(b>=a&&b>=c){
    cout<<b*10+a+c<<endl;
  }
  else{
    cout<<c*10+a+b<<endl;
  }
}