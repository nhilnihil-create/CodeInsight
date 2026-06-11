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
  ll N;
  cin>>N;
  vector<ll> A(N+1);
  A[0]=-1;
  for(ll i = 1; i <= N; i++) cin>>A[i];
  bool can = true;
  for(ll i = 1;i <= N; i++){
    if(A[i]>A[i-1]+1) can = false;
  }
  if(can){
    ll ans = 0LL;
    for(ll i = 0; i <= N; i++){
      if(i==N) ans+=A[N];
      else{
        if(A[i+1]<=A[i]) ans+=A[i];
      }
    }
    cout<<ans<<endl;
  }
  else cout<<-1<<endl;
}