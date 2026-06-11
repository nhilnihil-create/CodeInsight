#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> numbers;
  int input;
  bool status = false;

  for (size_t i = 0; i < 2; i++) {
    cin >> input;
    numbers.push_back(input);
  }

  for (size_t i = 1; i <= 3; i++) {
    if(numbers[0] * numbers[1] * i % 2 != 0) {
      status = true;
      break;
    }
  }
  
  cout << (status ? "Yes" : "No") << endl;

  return 0;
}
