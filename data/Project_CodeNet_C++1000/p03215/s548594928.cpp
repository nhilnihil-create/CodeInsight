#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int main(){
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  REP(i, N){
    cin >> a[i];
  }
  vector<ll> bubun;
  REP(i, N){
    ll sum = 0;
    FOR(j, i, N){
      sum += a[j];
      bubun.push_back(sum);
    }
  }
  ll x = 0;
  REPR(i, 43){
    int cnt = 0;
    ll bit = (1LL << (i-1));
    REP(j, bubun.size()){
      if(((x+bit)&bubun[j]) == (x+bit)){
        cnt++;
      }
    }
    // cout << "i:" << i << " cnt:" << cnt << endl;
    if(cnt >= K){
      x += bit;
    }
  }
  cout << x << endl;
  return 0;
}
