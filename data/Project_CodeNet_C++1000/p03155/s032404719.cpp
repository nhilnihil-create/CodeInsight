#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  H = N - H + 1;
  W = N - W + 1;
  cout << H * W << endl;
}
