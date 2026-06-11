#include<iostream>
using namespace std;

int main() {
	long long X, Y;
	cin >> X >> Y;
	int len = 1;
	long long temp = X;
	while (temp*2 <= Y)
	{
		temp *= 2;
		++len;
	}
	cout << len;

	return 0;
}