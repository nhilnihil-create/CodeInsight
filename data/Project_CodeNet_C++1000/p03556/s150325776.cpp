#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  int64_t n;
  cin>>n;
  for(int64_t i=0;i<pow(n,0.5)+2;i++){
      if(i*i>n){
    cout<<(i-1)*(i-1);
      break;
      }
  }
}