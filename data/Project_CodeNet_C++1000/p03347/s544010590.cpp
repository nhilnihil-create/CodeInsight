#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// constexpr ll INF = 1LL << 60;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  ll cnt = 0;
  int pre = 0;
  bool isOk = true;
  REPR(i, N-1){
    if(A[i] < pre-1){
      isOk = false;
      break;
    }
    if(pre-1 == A[i]){
      pre = A[i];
    }
    else if(A[i] > i){
      isOk = false;
      break;
    }
    else{
      cnt += A[i];
      pre = A[i];
    }
  }
  if(isOk){
    cout << cnt << endl;
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}

