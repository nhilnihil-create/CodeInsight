#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  string A, B, C; cin >> A >> B >> C;
  int ans = 0;
  REP(i, N){
    int cnt = 0;
    if(A[i] != B[i]) cnt++;
    if(B[i] != C[i]) cnt++;
    if(C[i] != A[i]) cnt++;
    if(cnt == 3) ans += 2;
    if(cnt == 2) ans += 1;
  }
  cout << ans << endl;
}