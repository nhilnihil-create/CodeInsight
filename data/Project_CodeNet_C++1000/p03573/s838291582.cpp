#include <iostream>
using namespace std;
int A, B, C;
int main()
{
	cin >> A >> B >> C;
	while (A > 100 || A < -100 || B>100 || B < -100 || C>100 || C < -100)
		cin >> A >> B >> C;
	if (A == B)
		cout << C << endl;
	else if (B == C)
		cout << A << endl;
	else if (A == C)
		cout << B << endl;

	return 0;
}