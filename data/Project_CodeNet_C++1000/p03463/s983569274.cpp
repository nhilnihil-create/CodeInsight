#include <iostream>

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  cout << ((B-A)%2 ? "Borys" : "Alice") << endl;
}
