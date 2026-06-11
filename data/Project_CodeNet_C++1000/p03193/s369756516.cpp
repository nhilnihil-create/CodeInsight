#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  int ret = 0;
  while(N--) {
    int a, b;
    cin >> a >> b;
    ret += a >= H && b >= W;
  }
  cout << ret << endl;
}



