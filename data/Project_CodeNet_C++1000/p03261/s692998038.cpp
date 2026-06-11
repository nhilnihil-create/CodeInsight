#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_shiritori(void) {
	int n;
	string s[100];
	string judge = "Yes";

	cin >> n;
	for (int i = 0; i < n; i++)cin >> s[i];

	for (int i = 1; i < n; i++) {
		string pre = s[i - 1];
		string now = s[i];
		if (pre[pre.size() - 1] != now[0]) {
			judge = "No";
			break;
		}
		for (int j = i - 1; j >= 0; j--) {
			if (s[j] == now) {
				judge = "No";
				break;
			}
		}
	}

	cout << judge << endl;
}

int main()
{
	b_shiritori();
    return 0;
}