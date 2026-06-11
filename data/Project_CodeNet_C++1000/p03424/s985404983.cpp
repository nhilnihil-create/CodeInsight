#include<iostream>
using namespace std;
 
int main(){
  int n,flag[4]={},i;
  char s[100];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> s[i];
    if(s[i]=='Y'){
      flag[0]=1;
       break;
    } 
  }
  if(flag[0]){
    cout<<"Four"<<endl;  
  }
  else{
cout<<"Three"<<endl;
  }
  }