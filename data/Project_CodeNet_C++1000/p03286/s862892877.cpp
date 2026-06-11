#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ans;

int main(void)
{
	int n, i;

	scanf("%d" ,&n);

	if (n == 0)
	{
		printf("0");
		return 0;
	}

	for (i = 0; n != 0; i++)
	{
		if ((n + (int)1e9) % 2 == 1)
		{
			ans.push_back(1);
			n--;
		}
		else
			ans.push_back(0);

		n /= -2;
	}

	for (i = ans.size() - 1; i >= 0; i--)
		printf("%d" ,ans[i]);
	return 0;
}