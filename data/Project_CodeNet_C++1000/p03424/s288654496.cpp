#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int p = 0;
	int w = 0;
	int g = 0;
	int y = 0;

	for (int i = 0; i < n; ++i) {
		char s;
		cin >> s;

		

		if (s == 'P') {
			++p;
		}
		else if (s == 'W') {
			++w;
		}
		else if (s == 'G') {
			++g;
		}
		else if (s == 'Y') {
			++y;
		}
	}
	if (p > 0 && w > 0 && g > 0 && y > 0) {
		cout << "Four" << endl;
	}
	else if (p > 0 && w > 0 && g > 0 && y == 0) {
		cout << "Three" << endl;
	}
}
