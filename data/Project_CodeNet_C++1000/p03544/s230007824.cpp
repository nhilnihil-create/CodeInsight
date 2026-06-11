#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;

int main() {
  cin >> N;
  long long int a = 2;
  long long int b = 1;
  while (N--) {
    b += a;
    a = b - a;
  }
  cout << a << endl;

  return 0;
}
