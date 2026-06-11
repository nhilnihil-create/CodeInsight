#include <iostream>
using namespace std;

int main() {
	int A;
  int B;
  double T;
  int security_keksz=0;
  cin >> A;
  cin >> B;
  cin >> T;
  T+=0.5;
  security_keksz=(T/A);
  cout << security_keksz*B;
	return 0;
}
