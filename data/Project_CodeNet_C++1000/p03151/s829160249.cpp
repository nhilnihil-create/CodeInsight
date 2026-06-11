#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,M=0,ans=0; cin>>N;
  vector<int64_t> A(N),B(N),C(N);
  rep(i,N) cin>>A.at(i);
  rep(i,N) cin>>B.at(i);
  rep(i,N){
    auto a=A.at(i),b=B.at(i);
    auto c=a-b;
    if(c<0){
      ans++;
      M+=-1*c;
    }
    else C.push_back(c);
  }
  sort(C.begin(),C.end());
  reverse(C.begin(),C.end());
  int64_t i=0,t=C.size();
  while(M>0&&i<t){
    M-=C.at(i);
    ans++;
    i++;
  }
  if(M>0) cout<<-1;
  else cout<<ans;
}
