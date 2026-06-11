#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	bool res = false;
	for (int i = 0; i * 4 <= n; i++) {
		for (int j = 0; j * 7 <= (n - i * 4); j++) {
			if (n == i * 4 + j * 7) {
				res = true;
			}
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
}