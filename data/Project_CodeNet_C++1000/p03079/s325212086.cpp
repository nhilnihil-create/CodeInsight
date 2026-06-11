#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  string result = (a == b && b == c) ? "Yes" : "No";
  cout << result << endl;
  return 0;
}
