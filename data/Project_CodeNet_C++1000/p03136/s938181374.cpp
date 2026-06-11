#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int max_l = 0;
  int sum = 0;
  int l;
  rep(i, N) {
    cin >> l;
    sum += l;
    max_l = max(max_l, l);
  }
  if (max_l * 2 < sum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}