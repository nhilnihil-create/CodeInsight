#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){

  int N;
  int x;
  cin>>N>>x;
  vector<int>A(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  int ans=0;
  for(int i=0;i<=N-1;i++){
  
    if(A[i]<=x){
    
      ans++;
      x-=A[i];
    }
    else{
    
      break;
    }
    if(i==N-1){
    
      if(x>0)ans--;
    }
  }
  cout<<ans;
}