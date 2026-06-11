#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main() 
{
	int ans = 0;
	for (int i = 1;i <= 4;i++)
	{
		int a;
		scanf("%1d",&a);
		if (a == 2)
			ans++;
	}
	cout << ans << endl;
    return 0;
}