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
  
  string S;
  cin>>S;
  
  int check=0;
  
  int ans=0;
  
  
  string X,Y;
  
   for(int i=0;i<N-1;i++) {
    X=S.substr(0,i+1);
    Y=S.substr(i+1);
    sort(X.begin(),X.end());
    for(int j=0;j<X.size();j++) {
      if(j==0||X[j]!=X[j-1]) {
        for(int k=0;k<Y.size();k++) {
          if(X[j]==Y[k]) {
            check++;
            break;
          }
        }
      }
    }
    
    if(check>ans){
      ans=check;
    }
    check=0;
  }
  
  cout<<ans<<endl;
}