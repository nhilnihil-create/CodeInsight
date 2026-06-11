#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int main(){
  int N;
  string A, B, C;
  cin >> N;
  cin >> A >> B >> C;
  int cnt = 0;
  REP(i, N){
    if(A[i] != B[i] && B[i] != C[i] && C[i] != A[i]){
      cnt+= 2;
    }
    else if(A[i] != B[i] || B[i] != C[i] || C[i] != A[i]){
      cnt += 1;
    }
  }
  cout << cnt << endl;
  return 0;
}
