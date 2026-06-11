#include <iostream>
using namespace std;
int main()
{
	int n = 0,ans = 0,max = 0,s = 0;
	cin >> n;
	for(int i = 0;i < n;i ++)
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