#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  char a, b;
  cin >> a >> b;
  if(a > b) cout << ">\n";
  else if(a < b) cout << "<\n";
  else cout << "=\n";
}
