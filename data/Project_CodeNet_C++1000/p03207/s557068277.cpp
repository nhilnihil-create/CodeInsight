#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, const char *argv[]) {
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  vector<int>::iterator iter = max_element(p.begin(), p.end());
  size_t index = distance(p.begin(), iter);
  int sum = accumulate(p.begin(), p.end(), 0) - p[index];

  cout << sum + p[index] / 2 << endl;
  return 0;
}
