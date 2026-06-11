#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
  int r;
  cin >> r;
  if (r<1200) printf("ABC\n");
  else if (r<2800) printf("ARC\n");
  else printf("AGC\n");
}