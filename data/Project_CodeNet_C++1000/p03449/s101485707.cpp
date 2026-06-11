#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int A[2][N];
  for(int i=0;i<N;i++) cin>>A[0][i];
  for(int i=0;i<N;i++) cin>>A[1][i];
  vector<int> C(100,0);
  for(int i=0;i<N;i++){
    int ans=0;
    for(int j=0;j<=i;j++) ans+=A[0][j];
    for(int j=i;j<N;j++) ans+=A[1][j];
    C.at(i)=ans;
  }
  sort(C.begin(),C.end());
  reverse(C.begin(),C.end());
  cout<<C.at(0)<<endl;
}
