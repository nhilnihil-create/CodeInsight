#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
  }
  bool flag=0;
  int checknum=1;
  int count=0;
  while(flag==0){
  
    checknum*=2;
    for(int i=0;i<=N-1;i++){
    
      if(A[i]%checknum!=0){
      
        flag=1;
        break;
      }
    }
    if(flag==0)count++;
  }
  cout<<count;
  return 0;
}