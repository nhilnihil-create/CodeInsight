#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int i = n;
	while (1) {
		if (i % 2 == 0) {
			cout << i << endl;
			break;
		}
		i += n;
	}

	return 0;
}
