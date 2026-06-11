#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> A(N), B(N);
  REP(i, N){
    cin >> A[i];
  }
  REP(i, N){
    cin >> B[i];
  }
  int ans = 0;
  REP(i, N){
    int res = 0;
    REP(j, N){
      if(i < j){
        res += B[j];
      }else if(i == j){
        res += A[j]+B[j];
      }else{
        res += A[j];
      }
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
}