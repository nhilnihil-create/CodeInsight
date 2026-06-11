#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  s += s;
  for (int i=0; i<t.length(); i++) {
    int check = 0;
    for (int j=0; j<t.length(); j++) {
      if (s[i+j]!=t[j]) check = 1;
    }
    if (check == 0) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}