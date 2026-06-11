#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int s;
  cin>>s;  int X;
  vector<int> A;
  X=s;
  A.push_back(s);
  for(int i=0;i<100000000;i++){
    
    if(X%2==0){
      X=X/2;
      A.push_back(X);
      
      for(int j=0;j<i;j++){
        if(A.at(j)==A.at(i)){
          cout<<i+1<<endl;
          return 0;
        }
      }
    }

      
    if(X%2==1){
      X=X*3+1;
      A.push_back(X);
      
      for(int j=0;j<i;j++){
        if(A.at(j)==A.at(i)){
          cout<<i+1<<endl;
          return 0;
        }
       }
    }
  }
}


      
      

    
