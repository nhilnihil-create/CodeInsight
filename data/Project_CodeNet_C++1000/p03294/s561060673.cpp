#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>a[i];
  }
  long long ans=0;
  for(int i=0;i<=N-1;i++){
  
    ans+=a[i]-1;
  }
  cout<<ans;
  return 0;
}