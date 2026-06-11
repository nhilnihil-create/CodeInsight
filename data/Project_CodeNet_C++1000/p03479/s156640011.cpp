#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int64_t X, Y;
  cin >> X >> Y;
  
  int64_t result = 0;
  
  for (int64_t i = X; i <= Y; i*= 2) {
    ++result;
  }
  
  cout << result << endl;
  
  return 0;
}
