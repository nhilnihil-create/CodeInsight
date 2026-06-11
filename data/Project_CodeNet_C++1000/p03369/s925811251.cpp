#include <iostream>
using namespace std;


int main()
{
	string a;
	cin >> a;
	int b = 0;
	for (int i = 0; i <3; i++) {

		if (a[i] == 'o') {
			b++;
		}
	}
	cout << 700 + (b * 100) << endl;
}

