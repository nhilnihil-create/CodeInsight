#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int64_t N,t=1,ans=0; cin>>N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  vector<int64_t> C(N);
  vector<pair<int64_t,int64_t>> T(N);
  rep(i,N){
    int64_t a,b; cin>>a>>b;
    A.at(i)=a;
    B.at(i)=b;
    T.at(i)=make_pair(a+b,i);
  }
  sort(T.begin(),T.end());
  reverse(T.begin(),T.end());
  rep(i,N){
    auto k=T.at(i).second;
    if(t>0)ans+=A.at(k);
    else ans-=B.at(k);
    t*=-1;
  }
  cout<<ans;    
}