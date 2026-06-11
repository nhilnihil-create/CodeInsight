#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 int A,B;
 cin >> A >> B;
 int ans = max({A + B, A - B, A * B});

  cout << ans;
  return 0;
}

