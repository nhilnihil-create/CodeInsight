#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<string> W(N);
  for(int i=0;i<N;i++){
    cin>>W[i];
  }
  
  bool res_1=true;
  
  bool res_2=true;
  
  
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(W[i]==W[j]){
        res_1=false;
        break;
      }
    }
  }
  
  if(res_1){
    for(int i=0;i<N-1;i++){
      if(W[i][W[i].size()-1]!=W[i+1][0]){
        res_2=false;
        break;
      }
    }
    if(res_2){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  else{
    cout<<"No"<<endl;
  }
}