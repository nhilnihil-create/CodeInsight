#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
	int a, b;
	cin >> a >> b;
	if (a + b == 15)
	{
		cout << "+" << endl;
	}
	else if (a * b == 15)
	{
		cout << "*" << endl;
	}
	else
	{
		cout << "x" << endl;
	}
}

int main()
{
	solve();
	return(0);
}