#include <iostream>
#include <string>

using namespace std;
int main()
{
	string a;
	cin >> a;
	int p = a.at(0);
	int o = a.at(1);
	int r = a.at(2);
	int w = a.at(3);

	int x = (p * 100) + (o * 10) + r;
	int z = (o * 100) + (r * 10) + w;

	if (x % 111 == 0 || z % 111 == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}