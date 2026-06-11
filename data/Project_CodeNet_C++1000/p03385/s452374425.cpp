#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if(s == "abc") cout << "Yes\n";
  else cout << "No\n";
}