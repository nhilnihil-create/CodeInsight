#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int T, X;
	cin >> T >> X;

	double result = static_cast<double>(T) / X;

	cout << result <<endl;

	return 0;
}
