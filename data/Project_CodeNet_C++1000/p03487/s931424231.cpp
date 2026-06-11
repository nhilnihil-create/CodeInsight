#include <bits/stdc++.h>
using namespace std;





int main(){
  
 
  int n;
  cin>>n;
  
  vector<int> data(n);
  
  for (int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    data.at(i)=tmp;
  }
  
  map<int,int> howmany;
  
  for (int x:data){
    if (howmany.count(x)){
      howmany.at(x)++;
    }
    
    else {
      howmany[x]=1;
    }
  }
  
  int answer=0;
  
  for (auto onepair:howmany){
    if (onepair.first>onepair.second){
      answer+=onepair.second;
    }
    
    else if (onepair.first<onepair.second){
      answer+=(onepair.second-onepair.first);
    }
  }
  
  cout<<answer<<endl;
  
    

  
    
    
    

      
  
    

  
  
    
  
  
  
}