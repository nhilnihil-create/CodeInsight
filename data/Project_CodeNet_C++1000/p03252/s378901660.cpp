#include <bits/stdc++.h>
using namespace std;
















int main(){

  
  string s,t;
  
  cin>>s>>t;
  
  map<char,char>  data1;
  
 
  string answer="Yes";
  
  for (int i=0;i<int(s.size());i++){
    if (data1.find(s.at(i))!=data1.end()){
      if (data1.at(s.at(i))!=t.at(i)){
        answer="No";
        break;
      }
    }
    
    else {
      data1[s.at(i)]=t.at(i);
    }
  }
  
  
  map<char,char> data2;
  
  
  for (int i=0;i<int(s.size());i++){
    if (data2.find(t.at(i))!=data2.end()){
      if (data2.at(t.at(i))!=s.at(i)){
        answer="No";
        break;
      }
    }
    
  else {
      data2[t.at(i)]=s.at(i);
    }
  }
  
  
  
  cout<<answer<<endl;
  
      
        
   

  

  
  
    
    
      
   
    
  
  
  

    
    
    

  
}