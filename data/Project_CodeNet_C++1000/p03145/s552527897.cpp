#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> lengths;
  int input;

  for (size_t i = 0; i < 3; i++) {
    cin >> input;
    lengths.push_back(input);
  }
  
  cout << (lengths[0] * lengths[1]) / 2 << endl;

  return 0;
}
