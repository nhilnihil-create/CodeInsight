#include <bits/stdc++.h>
using namespace std;


int main(){
  
  

  int n;
  cin>>n;
  
  vector<int> data(n+1);
  
  data.at(0)=0;
  
  for (int i=1;i<=n;i++){
    int count=data.at(i-1)+1;
    
    for (int j=6;j<=i;j*=6){
      int tmp=data.at(i-j)+1;
      count=min(tmp,count);
    }
    
    for (int j=9;j<=i;j*=9){
      int tmp=data.at(i-j)+1;
      count=min(tmp,count);
    }
    
    data.at(i)=count;
  }
  
  cout<<data.at(n)<<endl;
  
    
    

  
  

  
  
}