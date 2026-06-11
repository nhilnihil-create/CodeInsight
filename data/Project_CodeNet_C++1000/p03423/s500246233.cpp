#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n % 3 == 0) cout << n/3 << endl;
	else cout << (n - (n%3)) / 3 << endl;
	return 0;
}