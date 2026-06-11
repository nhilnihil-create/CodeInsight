#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC127 C - Prison
// 2020.07.04

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<int> V(N+1, 0);
  vector<int> VV(N+1, 0);
  REP(i, M){
    int l, r; cin >> l >> r; l--; r--;
    V[l]++;
    V[r+1]--;
  }
  REP(i, N){
    if(i != 0){
      VV[i] = VV[i-1] + V[i];
    }else{
      VV[i] = V[i];
    }
  }
  int ans = 0;
  REP(i, N){
    if(VV[i] == M){
      ans++;
    }
  }
  cout << ans << endl;
}