#include<iostream>

using namespace std;

int main()
{
	int a, x, y;
	cin >> a;
	x = a / 100;
	y = a % 100;
	if (1 <= x&&x <= 12) {
		if (1 <= y&&y <= 12) printf("AMBIGUOUS\n");
		else printf("MMYY\n");
	}
	else {
		if (1 <= y&&y <= 12) printf("YYMM\n");
		else printf("NA\n");
	}
}