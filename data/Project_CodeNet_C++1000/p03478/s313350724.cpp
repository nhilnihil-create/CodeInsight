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
  int N, A, B; cin >> N >> A >> B;
  int ans = 0;
  REP(i, N+1){
    int tmp = i;
    int res = 0;
    while(tmp > 0){
      res += tmp%10;
      tmp /= 10;
    }
    if(res >= A && res <= B){
      ans += i;
    }
  }
  cout << ans << endl;
}
