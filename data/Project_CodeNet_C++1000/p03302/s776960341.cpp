#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	if(a * b == 15)
	{
		printf("*");
	}
	else if(a + b == 15)
	{
		printf("+");
	}
	else
	{
		printf("x");
	}
	printf("\n");
	return 0;
}