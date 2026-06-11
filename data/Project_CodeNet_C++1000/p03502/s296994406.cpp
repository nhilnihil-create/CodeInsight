#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,l,a=0;
  cin>>n;
  l=n;
  
  for(int i=8;i>0;i--){
    int m=1;
    for(int j=0;j<i;j++){      
      m*=10;
    }
    int b=n/m;
    a+=b;
    n-=(b*m);
  }  
  a+=n;
  
  if(l%a==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }  
}