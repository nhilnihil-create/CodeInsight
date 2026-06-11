#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,y;
  cin>>n>>y;
  y/=1000;
  
  int a=y%5;
  y-=a;
 
  int b=y%10;
  
  y-=b;
  b/=5;
  int c=y/10;
  n-=a;
  n-=b;
  if(n>y||n<c){
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
    return 0;
  }
 
  for(int i=0; i<=c;i++){
    if((10*c-9*i-n)%4!=0){
      continue;
    }
    if(10*c-9*i<n||2*c-i>n){
      continue;
    }
    int k=(10*c-9*i-n)/4;
    cout<<i<<" "<<k+b<<" "<<10*c-10*i-5*k+a<<endl;
    return 0;
  }
  cout<<-1<<" "<<-1<<" "<<-1<<endl;
  
  
  
  
  
}