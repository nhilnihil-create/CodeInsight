#include<bits/stdc++.h>
using namespace std;
#define INF 10000000000
int main(){
  long long N,K;
  cin>>N>>K;
  vector<long long> H(N);
  for(long long i=0;i<N;i++){
    cin>>H.at(i);
  }
  sort(H.begin(),H.end());
  long long ans=INF;
  for(long long i=0;i<=N-K;i++){
    ans=min(ans,H.at(i+K-1)-H.at(i));
  }
  cout<<ans<<endl;
}
