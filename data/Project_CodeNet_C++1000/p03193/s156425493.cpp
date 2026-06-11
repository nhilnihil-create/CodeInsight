#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H, W, cnt=0;
  cin >> N >> H >> W;
  int a[N], b[N];
  for(int i=0; i<N; i++) {
    cin >> a[i] >> b[i];
    if(a[i]>=H&&b[i]>=W) {
      cnt++;
    }
  }
  cout << cnt << endl;
}