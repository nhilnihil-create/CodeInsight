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
  vector<int> ABC(3);
  REP(i, 3){
    cin >> ABC[i];
  }
  int K; cin >> K;
  int ans = 0;
  REP(i, 3){
    int res =  ABC[i];
    REP(j, K){
      res *= 2;
    }
    res += ABC[(i+1)%3] + ABC[(i+2)%3];
    ans = max(ans, res);
  }
  cout << ans << endl;
}
