#include <bits/stdc++.h>
using namespace std;

int main(){
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int x3, x4, y3, y4;
	x4 = -(y2 - y1) + x1;
	y4 = (x2 - x1) + y1;
	x3 = -(y1 - y4) + x4;
	y3 = (x1 - x4) + y4;
	printf("%d %d %d %d\n", x3, y3, x4, y4);
}
