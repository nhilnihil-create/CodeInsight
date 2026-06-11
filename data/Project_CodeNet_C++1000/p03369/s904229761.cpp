#include <iostream>
#include <string.h>
using namespace std;

void a_something_on_it(void) {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'o') sum += 100;
	}
	cout << sum+700 << endl;
}

int main()
{
	a_something_on_it();
    return 0;
}