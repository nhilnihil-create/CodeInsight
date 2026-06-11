#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B, K;
	cin >> A >> B >> K;

	for (int i = 0; i < K; i++) {
		if (i % 2 == 0) {
			//高橋君
			if (A % 2 == 1) {
				A -= 1;

			}
			A = A / 2;
			B += A;
		}
		else {
			//青木君
			if (B % 2 == 1) {
				B -= 1;

			}
			B = B / 2;
			A += B;
		}
	}
	cout << A << " " << B << endl;
	
}