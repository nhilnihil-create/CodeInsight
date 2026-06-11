#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
  string s;
  int res = 99999;

  cin >> s;

  for (int i = 0; i < s.size() - 2; i++)
  {
    int diff = abs(753 - stoi(s.substr(i, 3)));
    if (diff < res)
    {
      res = diff;
    }
  }

  cout << res << "\n";

  return 0;
}