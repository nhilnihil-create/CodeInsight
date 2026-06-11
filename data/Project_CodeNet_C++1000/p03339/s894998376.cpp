#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  vector<int> E(N),W(N);
  for (int i = 0; i != N-1; ++i) {
    if (S[i]=='E') {
      E[i+1] = E[i];
    } else {
      E[i+1] = E[i]+1;
    }
    if (S[N-i-1]=='W') {
      W[N-i-2] = W[N-i-1];
    } else {
      W[N-i-2] = W[N-i-1]+1;
    }
  }

  int ans {N};
  for (int i = 0; i !=N; ++i) {
    ans = min(ans,E[i]+W[i]);
  }
  cout << ans << endl;
}
