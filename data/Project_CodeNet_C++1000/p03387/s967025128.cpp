#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int maxi = max({a,b,c});

  if ((3*maxi-(a+b+c)) % 2 == 0) {
    cout << (3*maxi-(a+b+c)) / 2 << endl;
  } else {
    cout << (3*(maxi+1)-(a+b+c)) / 2 << endl;
  }
  return 0;
}