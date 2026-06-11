#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,D,X;cin>>N>>D>>X;
  int ans=0;
  for(int i=0;i<N;i++){
    int A;cin>>A;
    int Y=(D-1)/A;
    ans+=Y+1;
  }
  cout<<ans+X<<endl;
}
