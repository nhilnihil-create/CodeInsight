#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, T, A, x;
  cin >> N >> T >> A;
  vector<double> diff(N);
  rep(i, N) {
    int H;
    cin >> H;
    diff[i] = abs(T-H*0.006-A);
  }

  int res = min_element(diff.begin(), diff.end()) - diff.begin()+1;
  cout << res << endl;

  return 0;
}