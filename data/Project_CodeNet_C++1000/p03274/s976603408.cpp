#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL<<60;
int main() {
  int N,K; cin>>N>>K;
  vector<int64_t> M,P;
  P.push_back(0);
  rep(i,N){
    int64_t a; cin>>a;
    if(a<0) M.push_back(-1*a);
    else if(a>0) P.push_back(a);
    else K--;
  }
  M.push_back(0);
  reverse(M.begin(),M.end());
  int a=M.size()-1,b=P.size()-1;
  int64_t ans=INF;
  rep(i,K+1){
    if(i>b||K-i>a) continue;
    ans=min(ans,P.at(i)+M.at(K-i)+min(P.at(i),M.at(K-i)));
  }
  cout<<ans;
}