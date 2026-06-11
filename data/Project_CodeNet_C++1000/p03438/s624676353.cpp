#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  vector<ll> A(N),B(N);
  for(ll i = 0LL; i < N; i++) cin>>A[i];
  for(ll i = 0LL; i < N; i++) cin>>B[i];
  vector<ll> d(N);
  ll mi=0LL,pl=0LL;
  for(ll i = 0LL; i < N; i++){
    d[i]=B[i]-A[i];
    if(d[i]>0LL) pl+=d[i]-(d[i]%2LL);
    if(d[i]<0LL) mi-=d[i];
  }
  if(pl>=mi*2LL)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
  