#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> ls(n);
  vector<int> rs(n);
  for (int i = 0; i < n; i++) {
    cin >> ls[i];
    ls[i] *= 2;
    cin >> rs[i];
    rs[i] *= -2;
  }

  sort(ls.begin(), ls.end());
  reverse(ls.begin(), ls.end());
  sort(rs.begin(), rs.end());
  reverse(rs.begin(), rs.end());

  long long sum = 0, max = 0;
  for (int i = 0; i < n && (ls[i] >= 0 || rs[i] >= 0); i++) {
    if (max < sum + ls[i]) max = sum + ls[i];
    if (max < sum + rs[i]) max = sum + rs[i];
    sum += ls[i] + rs[i];
    if (max < sum) max = sum;
  }
  cout << max << endl;
}