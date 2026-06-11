#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  vector<char> x(a+b+1);
  string s="1234567890";
  for(int i=0;i<a+b+1;i++){
    cin>>x[i];
  }
  int z=0;
  for(int i=0;i<a+b+1;i++){
    if(i<a){
      for(int j=0;j<10;j++){
        if(x[i]==s[j]){
          z++;
          break;
        }
      }
    }
    else if(i==a){
      if(x[i]=='-'){
        z++;
      }
    }
    else if(i>a){
      for(int j=0;j<10;j++){
        if(x[i]==s[j]){
          z++;
          break;
        }
      }
    }
  }
  if(z==a+b+1){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}