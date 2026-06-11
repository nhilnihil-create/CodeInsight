#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N,M;
  cin>>N>>M;
  vector<int>K(N);
  int a=0;
  int likedata[N][30]={};
  for(int i=0;i<=N-1;i++){
  
    cin>>K[i];
    for(int k=0;k<=K[i]-1;k++){
    
      cin>>a;
      likedata[i][a-1]=1;
    }
  }
  int ans=0;
  bool flag=0;
  for(int i=0;i<=29;i++){
  
    flag=0;
    for(int k=0;k<=N-1;k++){
    
      if(likedata[k][i]==0){
        flag=1;
        break;
      }
    }
    if(flag==0)ans++;
  }
  cout<<ans;
}