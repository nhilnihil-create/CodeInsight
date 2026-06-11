#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;
const int B=10;
int main() {
  int64_t ans=-1*INF;
  int N; cin>>N;
  vector<vector<int64_t>> P(N,vector<int64_t>(11));
  vector<bitset<B>> S(N,0);
  rep(i,N){
    rep(j,10){
      int a; cin>>a;
      if(a==1) S.at(i).set(j,1);
    }
  }
  rep(i,N){
    rep(j,11){
      cin>>P.at(i).at(j);
    }
  }
  for(int i=1; i<(1<<B);i++){
    int64_t temp=0;
    bitset<B> s(i);
    rep(j,N){
      bitset<B> C=(S.at(j)&s);
      int c=C.count();
      temp+=P.at(j).at(c);
    }
    ans=max(temp,ans);
  }
  cout<<ans;
}
