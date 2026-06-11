#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  //input
  int N, M, C;
  cin >> N >> M >> C;
  vector <int> B(M);
  vector< vector<int> > A (N, vector<int>(M) );
  rep(i,M) cin >> B[i];
  rep(i,N){
    rep(j,M){
      cin >> A[i][j];
    }
  }

 //solve
 int ans = 0;  //正答するソースコードの個数
 rep(i,N){
   int sum = 0;  //正答のための条件となる不等式の左辺 - C
   rep(j,M){
     sum += A[i][j] * B[j];
   }
   if (sum > - C) ans ++;
 }

 //output
 cout << ans << endl;

}
