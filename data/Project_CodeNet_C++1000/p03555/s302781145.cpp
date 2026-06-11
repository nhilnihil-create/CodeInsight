#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

char c1[3];
char c2[3];

using namespace std;

int main() {
  cin >> c1[0] >> c1[1] >> c1[2];
  cin >> c2[0] >> c2[1] >> c2[2];

  cout << (c1[0] == c2[2] && c1[1] == c2[1] && c1[2] == c2[0] ? "YES" : "NO")
       << endl;

  return 0;
}
