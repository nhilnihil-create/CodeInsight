#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,M,ans=0; cin>>N>>M;
  vector<pair<int64_t,int64_t>> S(N);
  rep(i,N){
    int64_t a,b; cin>>a>>b;
    S.at(i)=make_pair(a,b);
  }
  sort(S.begin(),S.end());
  int64_t i=0;
  while(M>0){
    if(S.at(i).second>M){
      ans+=M*S.at(i).first;
      M=0;
    }
    else{
      ans+=S.at(i).first*S.at(i).second;
      M-=S.at(i).second;
    }
    i++;
  }
  cout<<ans;
}
