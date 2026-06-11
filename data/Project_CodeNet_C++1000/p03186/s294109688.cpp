#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C || A + B >= C)
		cout << B + C << endl;
	else
		cout << A + 1 + (B << 1) << endl;
	return 0;
}