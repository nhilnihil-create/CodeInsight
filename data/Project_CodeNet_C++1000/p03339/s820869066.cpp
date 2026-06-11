#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC098 C - Attention
// 2020.06.18

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  string S; cin >> S;
  vector<int> LW(N), RE(N);
  REP(i, N){
    if(i != 0){
      LW[i] = LW[i-1];
      RE[N-i-1] = RE[N-i]; 
    }
    if(S[i] == 'W') LW[i]++;
    if(S[N-i-1] == 'E') RE[N-i-1]++;
  }

  int ans = N;
  REP(i, N){
    int res;
    if(i == 0){
      res = RE[+1];
    }else if(i == N-1){
      res = LW[i-1];
    }else{
      res = LW[i-1] + RE[i+1];
    }
    ans = min(ans, res);
  } 
  cout << ans << endl;
}