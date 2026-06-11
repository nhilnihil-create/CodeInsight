#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,X; cin>>N>>X;
  vector<int64_t> S(N);
  rep(i,N){
    int64_t a; cin>>a;
    S.at(i)=abs(a-X);
  }
  auto ans=S.at(0);
  rep(i,N) ans=gcd(ans,S.at(i));
  cout<<ans;
}

