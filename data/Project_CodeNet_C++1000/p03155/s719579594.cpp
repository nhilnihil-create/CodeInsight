#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,H,W;
  cin >> N >> H >> W;
  cout << (N - H + 1) * (N - W + 1) << endl;
  return 0;
}