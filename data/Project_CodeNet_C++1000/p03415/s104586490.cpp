#include<cstdio>
#include<iostream>
using namespace std;
char a[5][5];
int main()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	printf("%c%c%c\n",a[1][1],a[2][2],a[3][3]);
	return 0;
} 