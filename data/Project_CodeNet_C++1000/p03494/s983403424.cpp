
#include <iostream>

using namespace std;
int main()
{

	int N, i, ads = 0, ans = 0;

	cin >> N;

	int S[200];

	for (i = 0; i < N; i++) {
		S[i] = 0;
		cin >> S[i];
	}

	while (true) {

		ads = 0;
		for (i = 0; i < N; i++) {

			if (S[i] % 2 == 0) {
				ads++;
				continue;
			}
			else
				break;
		}

		if (ads == N) {
			for (i = 0; i < N; i++) {
				S[i] = S[i] / 2;
			}
			ans++;
		}
		else
			break;
	}

	cout << ans << endl;
}
