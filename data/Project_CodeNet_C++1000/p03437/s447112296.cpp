
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	long long x, y;
	
	cin >> x >> y;

	if (x == y) {
		printf("-1\n");
	}
	else if(x < y){
		printf("%d\n", x);
	}
	else {
		if (x % y == 0) {
			printf("-1\n");
		}
		else {
			printf("%d\n", x);
		}
	}
}