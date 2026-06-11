#include <iostream>
using namespace std;

int main()
{
	int n, i, p = 0, w = 0, g = 0, y =0;
	char A;

	cin >> n;

	for (i = 0; i < n; i++) {

		cin >> A;

		if (A == 'P' && p == 0) {
			p++;
		}

		if (A == 'W' && w == 0) {
			w++;
		}

		if (A == 'G' && g == 0) {
			g++;
		}

		if (A == 'Y' && y == 0) {
			y++;
		}

	}

		int ans = p + w + g + y;

		if (ans < 4)
			cout << "Three" << endl;

		else
			cout << "Four" << endl;
	


}
