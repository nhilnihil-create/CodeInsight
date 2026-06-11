#include<iostream>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	if(abs(a-b)&1)
		cout << "Borys\n";
	else
		cout << "Alice\n";

	return 0;
}
