#include <iostream>

using namespace std;

int main() {
  long long int input;

  cin >> input;

  if(input % 2 == 0)
    cout << input << endl;
  else
    cout << input * 2 << endl;

  return 0;
}
