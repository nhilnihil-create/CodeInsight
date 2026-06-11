#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string ans;
  if(N%1111==0){
    ans="Yes";
  }
  else if((N/10)%111==0){
    ans="Yes";
  }
  else if((N%1000)%111==0){
    ans="Yes";
  }
  else{
  	ans="No";  
  }
  cout<<ans<<endl;
}