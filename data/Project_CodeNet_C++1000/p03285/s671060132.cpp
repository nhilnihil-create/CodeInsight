#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,c=0;
  cin>>N;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
      int K;
      K=4*i+7*j;
      if(N==K){
        c++;
      }
    }
  }
  if(c>0){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
}
