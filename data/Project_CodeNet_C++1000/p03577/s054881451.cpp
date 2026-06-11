#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const long long INF = 1LL << 60;
const long long P = 1000000007;

int main() {
  string s;
  cin >> s;
  int size = s.size() - 7;
  cout << s.substr(0,size-1) << endl;
  return 0;
}