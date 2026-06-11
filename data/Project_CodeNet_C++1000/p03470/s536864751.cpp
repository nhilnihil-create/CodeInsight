#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  vector<int> d;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp_d;
    cin >> tmp_d;
    d.push_back(tmp_d);
  }

  sort(d.begin(), d.end(), greater<int>());

  int counter = 1;
  int lower = d[0];
  for (int i = 1; i < n; i++) {
    if (d[i] == lower) {
      // skip
    } else {
      counter++;
      lower = d[i];
    }
  }
  cout << counter << endl;
  return 0;
}
