#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = 1;
  int ans1, ans2;

  for(int i=0; i<N; i++) {
    ans1 = ans*2;
    ans2 = ans+K;
    if(ans1 < ans2) ans = ans1;
    else ans = ans2;
  }
  cout << ans << endl;
}