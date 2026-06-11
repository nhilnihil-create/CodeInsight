#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<Int,Int> P;



int main(){ 
  int N, M; cin >> N >> M;
  vector<vector<bool>> like(N, vector<bool>(M,false));
  
  rep(i,N) {
    int K; cin >> K;
    rep(j,K) {
      int A; cin >> A;
      A--;
      like[i][A] = true;
    }
  }
  
  vector<bool> liked(M, true);
  rep(j,M) {
    rep(i,N) {
      if(!like[i][j]) liked[j] = false;
    }
  }
  
  int cnt = 0;
  rep(i,M) {
    if(liked[i]) cnt++;
  }
  cout << cnt << endl;
}


