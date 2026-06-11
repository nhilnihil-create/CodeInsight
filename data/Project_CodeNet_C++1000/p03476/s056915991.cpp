#include <bits/stdc++.h>
using namespace std; 
int main() {
  int N;
  cin>>N;
  int c=1;
  int d=99999;
  vector<int>result;
    for(int j=0;j<(d-c)/2+1;j++){
      int e=c+2*j;
      int f=0;
      if(e==1){
        f=1;
      }
      if(f==0){
        for(int k=1;k<(sqrt(e)+1)/2;k++){
          if(e%(2*k+1)==0){
            f=1;
          	break;
          }
        }
      }
      int g=(e+1)/2;
        if(g%2==0){
          f=1;
        }
      if(f==0){
        for(int l=1;l<sqrt(g)/2+1;l++){
          if(g%(2*l+1)==0){
            f=1;
          	break;
          }
        } 
      }
      if(e==3||e==5){
        f=0;
      }
      if(f==0){
        result.push_back(e);        
      }
    }
  int co=result.size();
  
  for(int i=0;i<N;i++){
    int g;
    int h;
    cin>>g;
    cin>>h;
    int count=0;
    
    for(int j=0;j<co;j++){
      
      if(g<=result.at(j)&result.at(j)<=h){
        count+=1;
        
      }
    }
    cout<<count<<endl;
  }
}

      

        
        
        
