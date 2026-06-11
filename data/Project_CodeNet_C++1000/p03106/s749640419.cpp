#include <iostream>
using namespace std;
int main()
{
	int a, b, k, n = 0;
	cin >> a >> b >> k;
	for (int i = 100; i>0; i--) {
		if (a%i==0 && b%i==0) {
			n = n + 1;
			if (n == k) {
				cout << i << endl;
				return 0;
		}
		}
	}
}