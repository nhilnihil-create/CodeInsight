#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N,K;
  cin>>N>>K;
  vector<int>h(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>h[i];
  }
  sort(h.begin(),h.end());
  int ans=-1;
  int check=0;
  for(int i=K-1;i<=N-1;i++){
  
    check=h[i]-h[i-K+1];
    if(ans>check||ans==-1)ans=check;
  }
  cout<<ans;
  return 0;
}