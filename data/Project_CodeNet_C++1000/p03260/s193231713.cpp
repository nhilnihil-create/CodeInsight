#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int A, B;
  cin >> A >> B;

  for(int i = 1; i<4;i++){
    if ((A * B * i) % 2 == 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
