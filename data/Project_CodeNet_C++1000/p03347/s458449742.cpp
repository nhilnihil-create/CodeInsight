#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int N;
vector<int> A;

int main(){
  cin >> N;
  A.resize(N+1);
  REP(i, N){
    cin >> A[i];
  }
  A[N] = -1;
  ll ans = 0;
  bool flag = true;
  REPR(i, N-1){
    if(A[i] > i){
      flag = false;
      break;
    }
    if(A[i+1] <= A[i]){
      ans += A[i];
    }
    else if(A[i] + 1 == A[i+1]){

    }
    else{
      flag = false;
      break;
    }
  }
  if(flag){
    cout << ans << endl;
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}
