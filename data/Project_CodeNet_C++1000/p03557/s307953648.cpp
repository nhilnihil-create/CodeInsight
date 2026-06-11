#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N;
  cin>>N;
  vector<ll> A(N),B(N),C(N);
  for(int i = 0; i < N;i++) cin>>A[i];
  for(int i = 0; i < N;i++) cin>>B[i];
  for(int i = 0; i < N;i++) cin>>C[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  ll ans = 0LL;
  for(int i = 0; i < N; i++) {
    int t = B[i];
    auto ia=lower_bound(A.begin(),A.end(),t);
    auto ic=upper_bound(C.begin(),C.end(),t);
    ans+=((ll)(ia-A.begin()))*(ll)(C.end()-ic);
  }
  cout<<ans<<endl;
}