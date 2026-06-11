#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int N;
  cin>>N;
  
  vector<string> S(N);
  for(int i=0;i<N;i++){
    cin>>S[i];
  }
  
  int M;
  cin>>M;
  
  vector<string> T(M);
  for(int j=0;j<M;j++){
    cin>>T[j];
  }
  
  int ans=0;
  
  
  for(int i=0;i<N;i++){
    int check=0;
    for(int j=0;j<N;j++){
      if(S[i]==S[j]){
        check++;
      }
    }
    for(int j=0;j<M;j++){
      if(S[i]==T[j]){
        check--;
      }
    }
    ans=max(ans,check);
  }
  
  cout<<ans<<endl;
}