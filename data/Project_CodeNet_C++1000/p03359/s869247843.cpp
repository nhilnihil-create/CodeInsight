#include <iostream>
using namespace std;
int main()
{
	int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", a > b ? a - 1 : a);
	return 0;
}