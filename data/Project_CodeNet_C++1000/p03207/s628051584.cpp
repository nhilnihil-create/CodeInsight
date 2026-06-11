#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  
  sort(A.begin(),A.end());
  
  int ans=A[N-1]/2;
  
  for(int i=0;i<N-1;i++){
    ans+=A[i];
  }
  
  
  cout<<ans<<endl;
}