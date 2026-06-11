#include <iostream>
using namespace std;

int main()
{	
	int N;
	long long K;
	cin >> N >> K;

	for (int man = 0; man <= N; man++) {
		for (int gosen = 0; gosen <= N - man; gosen++) {
			long long nokori = K - (10000 * man + 5000 * gosen);
			if (nokori % 1000 == 0 && nokori >= 0) {
				int sen = nokori / 1000;
				if (N == man + gosen + sen) {
					cout << man << " " << gosen << " " << sen << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;

}