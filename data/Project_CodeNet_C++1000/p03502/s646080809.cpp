#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, f = 0;
	cin >> x;
	int s=x;
	while (x > 0)
	{
		f += (x % 10);
		x /= 10;
	}
	
	((s % f) == 0) ? cout << "Yes" : cout << "No";
}