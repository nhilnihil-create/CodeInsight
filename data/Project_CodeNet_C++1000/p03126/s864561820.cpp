#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;cin>>N>>M;
  vector<int> F(M+1,0);
  for(int i=0;i<N;i++){
    int K;cin>>K;
    for(int j=0;j<K;j++){
      int A;cin>>A;
      F.at(A)++;
    }
  }
  int ans=0;
  for(int i=1;i<=M;i++){
    if(F.at(i)==N) ans++;
  }
  cout<<ans<<endl;
}
    