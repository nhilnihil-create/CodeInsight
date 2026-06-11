#include <bits/stdc++.h>

using namespace std;

void hawawa()
{
  string str;
  int num[3] = {};
  cin >> str;
  for (auto&& i : str) {
    num[i - 'a']++;
  }
  sort(begin(num), end(num));
  if (num[2] - num[0] < 2) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  hawawa();
  return 0;
}