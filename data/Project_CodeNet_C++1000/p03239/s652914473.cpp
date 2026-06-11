#include<iostream>
using namespace std;
int main()
{
  int n,T;
  cin>>n>>T;
  int count=0;
  int a=1001;
  for(int i=0;i<n;i++){
    int c,t;
    cin>>c>>t;
    if(t>T){
      count++;
    }
    else{
      if(a>c){
        a=c;
      }
    }
  }
  if(count==n){
    cout<<"TLE";
  }
  else{
    cout<<a;
  }
}
      
    
