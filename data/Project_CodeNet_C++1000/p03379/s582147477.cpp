#include <bits/stdc++.h>
using namespace std;






int main(){
  

  int n;
  cin>>n;
  
  vector<int> rawdata(n);
  
  for (int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    rawdata.at(i)=tmp;
  }
  
  auto sortdata=rawdata;
  
  sort(sortdata.begin(),sortdata.end());
  
  for (int i=0;i<n;i++){
    if (rawdata.at(i)<=sortdata.at((n/2)-1)){
      cout<<sortdata.at(n/2)<<endl;
    }
    
    else {
      cout<<sortdata.at((n/2)-1)<<endl;
    }
    
  }
  
  
  

  
    
  


    
  
  
  
}