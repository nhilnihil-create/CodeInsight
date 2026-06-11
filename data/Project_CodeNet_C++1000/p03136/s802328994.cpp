#include <iostream>
using namespace std;
int main()
{
	int n,ans = 0,max = 0,s;
	cin >> n;
	while(n --)
	{
		cin >> s;
		max = max > s ? max : s;
		ans += s;
	}
	if(ans > 2 * max)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}