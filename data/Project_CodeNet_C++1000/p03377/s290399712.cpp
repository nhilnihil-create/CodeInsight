#include <iostream>
using namespace std;
int main()
{
	int a, b, x;
	bool flag = true;
	cin >> a >> b >> x;
	for (int i = 0; i <= b; i++) {
		if ((a + b) < x) {
			cout << "NO";
			flag = false;
			break;
		}else if ((a + i) <= x) {
			cout << "YES";
			flag = false;
			break;
		}
	}
	if (flag) cout << "NO";
	return 0;
}