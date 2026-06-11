#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	long long  K, A, B;
	cin >> K >> A >> B;

	long long ans = 1;
	if (A >= B) {
		cout << K + 1 << endl;
	}
	else {
		for (long long i = 1; i <= K; i++) {
			if (ans < A) {
				ans += 1;
			}
			else if (A <= ans && i < K) {
				ans += B - A;
				i++;
			}
			else if (i == K) {
				ans += 1;
			}
		}
		cout << max(ans, K + 1) << endl;
	}


	return 0;
}