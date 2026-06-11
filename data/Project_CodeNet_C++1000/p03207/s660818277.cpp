#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int S=0,M=0;
  for(int i=0;i<N;i++){
    int P;
    cin>>P;
    S+=P;
    M=max(M,P);
  }
  int ans=S-M/2;
  cout<<ans<<endl;
}