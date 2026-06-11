#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,d,x;
  cin>>r>>d>>x;
  int a=0;
  for(int i=0;i<10;i++){
    if(i==0){
      cout<<x*r-d<<endl;
      a=x*r-d;
    }
    else{
      cout<<a*r-d<<endl;
      a=a*r-d;
    }
  }
}