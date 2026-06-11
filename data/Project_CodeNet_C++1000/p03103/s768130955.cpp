#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000007

int main (){
  int N,M;
  long long ans=0;
  cin>>N>>M;
  vector<pair<long long,long long>>energy(N);
  rep(i,N){
    long long a,b;
    cin>>a>>b;
    energy[i]=make_pair(a,b);
  }
  sort(energy.begin(),energy.end());
  for(int i=0;i<N;i++){
    if(energy[i].second>=M){
      ans+=energy[i].first*M;
      cout<<ans;
      return 0;
    }
    else{
      M-=energy[i].second;
      ans+=energy[i].first*energy[i].second;
    }
  }
}
