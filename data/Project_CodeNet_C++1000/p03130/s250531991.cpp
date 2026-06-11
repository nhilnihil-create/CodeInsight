#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  vector<int> a(3), b(3);
  for (int i=0; i<3; i++) cin >> a[i] >> b[i];
  vector<int> count(4, 0); // 各整数の登場回数
  for (int i=1; i<=4; i++) {
    for (int j=0; j<3; j++) {
      if (i==a[j]) count[i-1]++;
    }
  }
  for (int i=1; i<=4; i++) {
    for (int j=0; j<3; j++) {
      if (i==b[j]) count[i-1]++;
    }
  }
  sort(count.begin(), count.end());
  if (count[3]<3) cout << "YES" << endl;
  else cout << "NO" << endl;
}