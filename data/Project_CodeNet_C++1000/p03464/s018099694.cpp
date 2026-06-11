#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9


int main(){
  int K;
  cin >> K;
  vector<int> A(K);
  REP(i, K){
    cin >> A[i];
  }
  vector<ll> maxc(K+1), minc(K+1);
  maxc[K] = minc[K] =2;

  REPR(i, K-1){
    maxc[i] = A[i] * (maxc[i+1] / A[i]) + A[i]-1;
    minc[i] = A[i] * (minc[i+1] / A[i]);
    if(minc[i+1] % A[i] != 0){
      minc[i] += A[i];
    }
    ll maxn = A[i] *(maxc[i] / A[i]);
    ll minn = A[i] *(minc[i]/ A[i]);
    if(maxn < minc[i+1] || maxc[i+1] < maxn || minn < minc[i+1] || maxc[i+1] < minn){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << minc[0] << " " << maxc[0] << endl;
  return 0;
}
