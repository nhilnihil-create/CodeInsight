
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int r = 0;
	int b = 0;
	cin >> n;
	char* a = new char[100];
	cin >> a;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'R') r++;
		if (a[i] == 'B') b++;
	}
	if (r > b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;

}