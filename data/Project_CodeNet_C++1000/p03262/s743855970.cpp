#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
  int N,X;
  cin >> N >> X;

  vector<int> x(N);
  for (int i = 0; i < N; i++) {
      cin >> x.at(i);
      x.at(i) = abs(x.at(i) - X);
  }

  int ans = x.at(0);

  for (int i = 0; i < N; i++) {
      ans = gcd(ans,x.at(i));
  }

  cout << ans << endl;

}
