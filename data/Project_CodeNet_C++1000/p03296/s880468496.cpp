#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int ans=0;
  int A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=1;i<N;i++){
    if(A[i]==A[i-1]){
      ans++;
      if(i>=N-2) break;
      i++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
