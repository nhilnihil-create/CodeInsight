#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int ss =S.size();
  int count=0;
  int countmax=0;
  
  for(int i=0;i<ss-1;i++){
    if(S.at(i)=='A'||S.at(i)=='T'||S.at(i)=='G'||S.at(i)=='C'){
      count =1;
      for(int j=i+1;j<ss;j++){
        if(S.at(j)=='A'||S.at(j)=='T'||S.at(j)=='G'||S.at(j)=='C'){
          count ++;
        }
        else{ break;}
      }
    }
      if(count>countmax){
        countmax=count;}
  }
  
  if(S.at(ss-1)=='A'||S.at(ss-1)=='T'||S.at(ss-1)=='G'||S.at(ss-1)=='C'){
    count =1;
    if(count>countmax){countmax=1;}
  }
  
          
   cout << countmax <<endl;       
          
}