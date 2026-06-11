#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<string>W(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>W[i];
    for(int j=0;j<=i-1;j++){
    
      if(W[i]==W[j]){
      
        cout<<"No";
        return 0;
      }
    }
  }
  for(int i=0;i<=N-2;i++){
  
    if(W[i][W[i].length()-1]!=W[i+1][0]){
    
      cout<<"No";
      return 0;
    }
  }
  cout<<"Yes";
  return 0;
}