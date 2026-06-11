#include <iostream>
using namespace std;

int main() {
	int a, b;
  	string s = "x";
  	cin >> a >> b;
  	if (a + b == 15) s = "+";
  	if (a * b == 15) s = "*";
  	cout << s << endl;
  	return 0;
}