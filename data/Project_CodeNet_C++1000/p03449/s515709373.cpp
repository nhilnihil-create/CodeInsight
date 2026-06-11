#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 
  int N;
  cin>>N;
  vector<vector<int>>A(2,vector<int>(N));
  for(int i=0;i<=1;i++){
  
    for(int j=0;j<=N-1;j++){
    
      cin>>A[i][j];
    }
  }
  int ans=0;
  int count=0;
  for(int i=0;i<=N-1;i++){
  
    count=0;
    for(int j=0;j<=i;j++){
    
      count+=A[0][j];
    }
    for(int j=i;j<=N-1;j++){
    
      count+=A[1][j];
    }
    ans=max(ans,count);
  }
  cout<<ans;
  return 0;
}