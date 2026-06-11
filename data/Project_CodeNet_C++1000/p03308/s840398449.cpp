#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  sort(A.begin(),A.end());
  /*int ans=0;
  for(int i=1;i<N;i++){
    int X=A.at(i)-A.at(i-1);
    if(X>ans) ans=X;
  }
  cout<<ans<<endl;*/
  cout<<A.at(N-1)-A.at(0)<<endl;
}
