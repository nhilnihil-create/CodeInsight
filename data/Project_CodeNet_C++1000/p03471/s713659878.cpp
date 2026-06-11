#include <iostream>
using namespace std;

bool solve(long long N, long long Y) {

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N - i; j++) {
			int k = N - i - j;
			if (k >= 0 && k <= N - i - j) {
				long long T = 10000 * i + 5000 * j + 1000 * k;
				if (T == Y) {
					cout << i << " " << j << " " << k << endl;
					system("pause");
					return true;
				}
			}
		}

	return false;
}

int main(void) {
	
	long long N, Y;

	cin >> N >> Y;

	if (solve(N, Y))
		;
	else
	{
		cout << -1 << " " << -1 << " " << -1 << endl;
	}
	
}