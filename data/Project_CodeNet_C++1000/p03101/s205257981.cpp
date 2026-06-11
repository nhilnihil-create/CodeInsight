#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int H,W;
  cin >> H >> W;
  int h,w;
  cin >> h >> w;
  cout << H*W-(W*h+(H-h)*w) << endl;
}

