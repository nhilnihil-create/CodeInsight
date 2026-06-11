#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int T;
	int X;
	cin >> T;
	cin >> X;

	if (T > 0 &&
		T <= 100 &&
		T > 0 &&
		T <= 100)
	{
		float time = float(T)/float(X)
			;
		cout << time << endl;
	}
	cin >> T;
	return 0;
}