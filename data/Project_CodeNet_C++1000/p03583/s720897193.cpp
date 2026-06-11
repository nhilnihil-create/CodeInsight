#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	for (long long i = 1; i <= 3500; i++) {
		for (long long j = 1; j <= 3500; j++) {
			long long s = 4 * i * j - n * i - n * j, t = i * j * n;
			if (s != 0 && t % s == 0 && t / s > 0) {
				cout << i << " " << j << " " << t / s << endl;
				return 0;
			}
		}
	}

	return 0;
}