#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W,N;
  cin >> H >> W >> N;
  int X[N],Y[N];
  vector<int> R[H];
  map<P,bool> mp;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    X[i]--; Y[i]--;
    mp[make_pair(X[i],Y[i])] = true;
    R[X[i]].push_back(Y[i]);
  }
  for (int i = 0; i < H; i++) {
    if (!R[i].empty()) {
      sort(R[i].begin(),R[i].end());
    }
  }
  int DP[H];
  DP[0] = 1;
  for (int i = 1; i < H; i++) {
    if (mp[make_pair(i,DP[i-1])]) {
      DP[i] = DP[i-1];
    } else {
      DP[i] = DP[i-1] + 1;
    }
  }
  int ans = H;
  for (int i = 0; i < H-1; i++) {
    if (!R[i+1].empty()) {
      if (R[i+1][0]+1 <= DP[i]) {
        ans = i+1;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}