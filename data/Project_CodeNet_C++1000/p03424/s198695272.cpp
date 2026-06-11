
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, p, w, g, y, ans;
	string s;
	p = w = g = y = 0;
	ans = 4;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s == "P") {
			++p;
		}
		else if (s == "W") {
			++w;
		}
		else if (s == "G") {
			++g;
		}
		else if (s == "Y") {
			++y;
		}
	}

	if (p == 0) {
		--ans;
	}
	else if (w == 0) {
		--ans;
	}
	else if (g == 0) {
		--ans;
	}
	else if (y == 0) {
		--ans;
	}

	if (ans == 4)
	{
		cout << "Four" << endl;
	}
	else if (ans == 3)
	{
		cout << "Three" << endl;
	}

}

