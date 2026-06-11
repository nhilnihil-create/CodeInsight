#include<iostream>
#include <string>
using namespace std;
int main()
{
	int num_a, num_b;
	cin >> num_a >> num_b;

	int multi = num_a * num_b;

	if ((multi % 2) == 1) {
		cout << "Odd" << endl;
	}
	else {
		cout << "Even" << endl;
	}

	return 0;
}