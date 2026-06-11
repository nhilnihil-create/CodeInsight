#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define PI 3.141592653589793238
#define INF 1050000000

using vi = vector<int>;


int main() {

	int A;

	cin >> A;

	int B;
	cin >> B;
	int C;
	cin >> C;

	if (A-B)
	{
		if (B == C) {

			cout << A << endl;
		}
		else {

			cout << B << endl;
		}
	}
	else {

		cout << C << endl;
	}

	return 0;
}