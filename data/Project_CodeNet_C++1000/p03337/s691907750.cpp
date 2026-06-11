#include <iostream>
#include <queue>

using namespace std;

int main() {
  int a, b;
  priority_queue<int> results;

  cin >> a >> b;

  results.push(a + b);
  results.push(a - b);
  results.push(a * b);

  cout << results.top() << endl;

  return 0;
}
