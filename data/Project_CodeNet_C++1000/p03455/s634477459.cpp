
#include <iostream>

using namespace std;

void exec1()
{
	int a, b;
	cin >> a >> b;
	string answer;
	if (a % 2 == 0 || b % 2 == 0) {
		answer = "Even";
	}
	else {
		answer = "Odd";
	}

	cout << answer << endl;
}
int main()
{
	exec1();
	return 0;
}
