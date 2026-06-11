#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // Tenka1 Programmer Beginner Contest 2019 C - Stones
  // 白→黒、黒→白、何も変えなくても条件を満たす
  // 境目の配列を準備して、右側にある黒、左側にある白をカウントしていく
  // （変えなくてはいけない個数を把握するため）
  // そのあと、境目を左から順に見ていき、最小値を更新する
  int N; cin >> N;
  string S; cin >> S;
  
  vector<int> leftB(N+1, 0); // 境目の配列（左側にある黒）
  vector<int> rightW(N+1, 0); // 境目の配列（右側にある白）
  for(int i = 1; i < N+1; i++){
    if(S[i-1] == '#'){ // 左側にあるのが黒なら
      leftB[i] = leftB[i-1] + 1;
    }else{ // 白なら1を足さない
      leftB[i] = leftB[i-1];
    }
    if(S[N-i] == '.'){ //右側にあるのが白なら
      rightW[N-i] = rightW[N+1-i] + 1;
    }else{
      rightW[N-i] = rightW[N+1-i];
    }
  }
  
  int ans = 1e9;
  REP(i, N+1){  
    ans = min(ans, leftB[i]+rightW[i]);
  }
  cout << ans << endl;
}