#include<iostream>
#include<cmath>
using namespace std;
//long long int pow(long long int a,long long int p) {
//	long long int n = 1;
//	for (int i = 0; i < p; i++)
//		n *= a;
//	return n;
//}
int main(void)
{
	long long int N, P, P2, i = 2, j = 1, ans = 1;
	cin >> N >> P;
	P2 = P;
	/*while (i <= P2 / 2) {
		if (P%i == 0) {
			cnt++;
			P /= i;
		}
		else {
			i++;
		}
		if (cnt == N) {
			ans *= i;
			cout << ans << " " << i << endl;
			cnt = 0;
		}
	}
	if (P%P2==0)ans *= P2;*/
	if (N == 1) {
		cout << P << endl;
	}
	else if (P == 1) {
		cout << "1" << endl;
	}
	else if (N > 64) {
		cout << "1" << endl;
	}
	else {
		for (i = 2, j = (long long)pow(i, N); j <= P; i++, j = (long long)pow(i, N)) {
			if (P%j == 0) {
				ans = i;
			}

		}
		cout << ans << endl;
	}
	return 0;
}