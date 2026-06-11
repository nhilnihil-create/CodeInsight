#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<int> abc(3);
  rep(i, 3) cin >> abc[i];
  sort(abc.rbegin(), abc.rend());
  int ans = abc[0] * 10 + abc[1] + abc[2];
  cout << ans << endl;
}