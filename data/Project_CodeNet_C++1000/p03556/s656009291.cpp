#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int a,b;
  cin>>a;
  b=2;
  for(int i=0;i<100000;i++){
  	b=i*i;
    if(b>a){
      b=(i-1)*(i-1);
      break;
    }
  }
  
  if(a==1){b=1;}
  
  cout<<b<<endl;
  
}