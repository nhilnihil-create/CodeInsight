#include <iostream>
using namespace std;
typedef long long int LLI;

int main()
{
	LLI x, y, ans = 0;
	cin >> x >> y;
	while( x <= y )
	{
		x *= 2;
		ans++;
	}
	cout << ans;
}