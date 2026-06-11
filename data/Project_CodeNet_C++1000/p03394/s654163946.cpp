#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  vector<int> c;
  c.push_back(2);
  c.push_back(4);
  for (int i = 3; i <= 30000; ++i) {
    if (i % 6 == 3) {
      c.push_back(i);
    }
  }
  for (int i = 5; i <= 30000; ++i) {
    if (i % 6 == 2 || i % 6 == 4) {
      c.push_back(i);
    }
  }
  for (int i = 6; i <= 30000; ++i) {
    if (i % 6 == 0) {
      c.push_back(i);
    }
  }
  vector<int> ans;
  if (n % 2) {
    ans.push_back(c.back());
    c.pop_back();
    --n;
  }
  for (int i = 0; i < n; ++i) {
    ans.push_back(c[i]);
  }
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
