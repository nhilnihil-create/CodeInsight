#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <sstream>

using namespace std;

typedef long long ll;

ll ToInt(string s) {
  istringstream in(s);
  ll x;
  in >> x;
  return x;
}

int Sum(ll x) {
  int result = 0;
  while (x > 0) {
    result += x % 10;
    x /= 10;
  }
  return result;
}

int main()
{
  string s;
  cin >> s;

  int result = Sum(ToInt(s));

  if (s.size() > 1) {
    result = max<int>(result, 9 * (s.size() - 1));
  }

  for (int len = 1; len < s.size(); ++len) {
    string prefix = s.substr(0, len);
    ll p = ToInt(prefix) - 1;
    if (p > 0) {
      result = max<int>(result, Sum(p) + 9 * (s.size() - prefix.size()));
    }
  }

  cout << result << endl;

  return 0;
}
