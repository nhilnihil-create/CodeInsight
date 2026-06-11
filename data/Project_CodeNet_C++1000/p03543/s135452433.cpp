#include <iostream>
using namespace std;

int main() {
	string integer;
	cin >> integer;
	char check = integer[1];

	if ((integer[0] == check && integer[2] ==check|| integer[3] == check && integer[2]==check)) {
		cout<<"Yes";
	}
	else {
		cout<<"No";
	}
	return 0;
}