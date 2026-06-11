#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

void solve(int a, int b) {
  cout << ((a * b % 2) ? "Odd" : "Even") << endl;
}

int main(){
  // int 3E4
  // long 2E9
  // long long 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  solve(a, b);
  return 0;
}
