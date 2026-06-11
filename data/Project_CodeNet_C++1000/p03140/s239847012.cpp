#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  string A,B,C;
  cin>>N>>A>>B>>C;
  int ans=0;
  for(int i=0;i<N;i++){
    int v=(A[i]==B[i])+(B[i]==C[i])+(C[i]==A[i]);
    if(v<3)v++;
    ans+=3-v;
  }
  cout<<ans<<endl;
}
