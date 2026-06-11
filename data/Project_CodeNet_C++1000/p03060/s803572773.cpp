#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int V[N],C[N],A[N];
  for(int i=0;i<N;i++) cin>>V[i];
  for(int i=0;i<N;i++) cin>>C[i];
  for(int i=0;i<N;i++) A[i]=V[i]-C[i];
  sort(A,A+N);
  reverse(A,A+N);
  int ans=0;
  for(int i=0;i<N;i++){
    if(A[i]>0) ans+=A[i];
    else break;
  }
  cout<<ans<<endl;
}
