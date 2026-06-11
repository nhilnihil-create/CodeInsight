
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A, B;

	cin >> A;
	cin >> B;

	if ((A*B) % 2 == 1) {
		cout << "Odd";
	}
	else {
		cout << "Even";
	}

	return 0;
}
