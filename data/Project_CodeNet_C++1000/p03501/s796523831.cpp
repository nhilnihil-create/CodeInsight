#include <iostream>
#include <string>

using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = a * b;

	cout << min(d, c);
}