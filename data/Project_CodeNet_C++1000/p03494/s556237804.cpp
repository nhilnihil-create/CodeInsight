#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,count=0;
  cin>>a;
  vector<int> data(a);
  
  for(int i=0;i<a;i++){
    cin>>data.at(i);
  }
  
  bool ending=false;
  
  while(true){
    
    for(int j=0;j<a;j++){
      if(data.at(j)%2==1){
        ending=true;
        break;
      }
      else if(data.at(j)%2==0){
      data.at(j)/=2;      
      if(j==a-1){
        count++;
      }
      }
    }  
    
    if(ending==true){
      break;      
    }
  }
  
    cout<<count<<endl;
}