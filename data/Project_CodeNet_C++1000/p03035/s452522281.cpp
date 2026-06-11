#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a; int b;
	cin >> a >> b;
	if (a <= 5) cout << 0 << endl;
	if (6 <= a && a <= 12) cout << b / 2 << endl;
	if (a > 12) cout << b << endl;
	return 0;
}