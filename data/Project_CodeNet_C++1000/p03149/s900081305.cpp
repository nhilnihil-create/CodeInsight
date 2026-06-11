#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long MOD = 1e9;

int main() {
  vector<int> num(10, 0);
  for (int i = 0; i < 4; ++i) {
    int a;
    cin >> a;
    num[a]++;
  }
  if (num[1] == 1 && num[9] == 1 && num[7] == 1 && num[4] == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}