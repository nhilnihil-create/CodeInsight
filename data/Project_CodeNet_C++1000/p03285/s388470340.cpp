#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

void b_cakes_and_donuts(void) {
	int n;
	string judge = "No";
	cin >> n;
	for (int i = 0; i <= 25; i++) {
		if (4 * i > n)continue;
		for (int j = 0; j <= 14; j++) {
			if (4 * i + 7 * j == n) {
				judge = "Yes";
				break;
			}
		}
		if (judge == "Yes") break;
	}
	cout << judge << endl;
}

int main()
{
	b_cakes_and_donuts();
    return 0;
}