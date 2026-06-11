#include <iostream>
#include<algorithm>
using namespace std;
int main(void)
{	int N, A, B,P,P1,P2,P3;
	P1 = P2 = P3 = 0;
	cin >> N;
	cin >> A >> B;
	for (int i = 0; i < N; i++) {
		cin >> P;
		if (P <= A) {
			P1++;
		}
		else if (A + 1 <= P && P <= B) {
			P2++;
		}
		else if (B + 1 <= P) {
			P3++;

		}

	}

	cout << min({ P1,P2,P3 }) << endl;
	return 0;

}
