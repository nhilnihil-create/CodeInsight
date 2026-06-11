#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  int input;
  vector<int> numbers;

  for (size_t i = 0; i < 3; i++) {
    cin >> input;
    numbers.push_back(input);
  }

  sort(numbers.begin(), numbers.end());

  cin >> input;

  for (size_t i = 0; i < input; i++) {
    numbers.back() *= 2;
  }

  long int count = 0;

  for(int &i : numbers) {
    count += i;
  }

  cout << count << endl;

  return 0;
}
