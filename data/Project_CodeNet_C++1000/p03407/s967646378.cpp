#include <iostream>
using namespace std;
int A, B, C;
int main()
{
	cin >> A >> B >> C;
	if (A != 0 && B != 0 && C != 0)
	{
		if ((A + B) - C >= 0)
			cout << "Yes\n";
		else 
			cout << "No\n";
	}

	return 0;
}