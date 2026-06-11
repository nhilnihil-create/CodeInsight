#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string a;
  cin >> a;
  if (a == "A") cout << "T" << endl;
  if (a == "T") cout << "A" << endl;
  if (a == "G") cout << "C" << endl;
  if (a == "C") cout << "G" << endl;
  return 0;
}