#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans=1;
  for (int i=2; i*i<N; i++) {
    for (int j=i; j<=N; j*=i) {
      ans=max(ans,j);
    }
  }
  cout << ans << "\n";
}
