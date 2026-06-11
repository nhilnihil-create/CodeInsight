#include <bits/stdc++.h>
using namespace std;



int64_t departure(int64_t arrival,int64_t f,int64_t s){
  if (arrival<=s){
    return s;
  }
  
  if (arrival>s){
    return ((arrival+f-1)/f)*f;
  }
}





int main(){
  


  int64_t n;
  cin>>n;
  
  vector<int64_t> cdata(n),sdata(n),fdata(n);
  
  for (int64_t i=1;i<=n-1;i++){
    int64_t c,s,f;
    cin>>c>>s>>f;
    cdata.at(i)=c;
    sdata.at(i)=s;
    fdata.at(i)=f;
  }
  
  for (int64_t i=1;i<=n;i++){
    
    int64_t arrival=0;
    
    for (int64_t j=i+1;j<=n;j++){
      arrival=departure(arrival,fdata.at(j-1),sdata.at(j-1))+cdata.at(j-1);
    }
    
    cout<<arrival<<endl;
  }
  
  
    
      
  

      
  
    

  
  
    
  
  
  
}