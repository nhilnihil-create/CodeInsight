#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int n = s.size();

  if (s[0] == '0' || s[n - 1] == '1') {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[n - 2 - i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  vector<int> st = {1};
  for (int i = 0; i < n - 1; ++i) {
    cout << st.back() << " " << i + 2 << endl;
    if (s[i] == '1') st.push_back(i + 2);
  }

  return 0;
}
