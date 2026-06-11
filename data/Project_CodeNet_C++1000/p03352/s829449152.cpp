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
  int X; cin >> X;
  int ans = 1;
  for(int i = 1; i*i <= X; i++){
    int tmp = i;
    for(int j = 2; j <= 10; j++){
      tmp *= i;
      if(tmp > X) break;
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}