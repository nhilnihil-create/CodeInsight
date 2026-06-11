#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	if (n / 2 <= n - k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}