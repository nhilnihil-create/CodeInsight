#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

string s;
int k;

int ans[300][300][301];

int Solve(int l, int r, int k) {
  if (k < 0) return -1000;
  if (l > r) return 0;
  if (l == r) return 1;
  int& result = ans[l][r][k];
  if (result != -1) return result;

  result = 0;

  result = max(result, Solve(l + 1, r, k));
  result = max(result, Solve(l, r - 1, k));
  result = max(result, 2 + Solve(l + 1, r - 1, k - (s[l] == s[r] ? 0 : 1)));

  return result;
}

int main()
{
  cin >> s >> k;

  memset(ans, -1, sizeof(ans));
  cout << Solve(0, s.size() - 1, k) << endl;
  
  return 0;
}
