#include<iostream>
using namespace std;
int main(){
int n;cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
  	char h;
    cin>>h;
    if(h=='R'){ans++;}
    else{ans--;}
  }
  if(ans>0){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  
  
return 0;
}