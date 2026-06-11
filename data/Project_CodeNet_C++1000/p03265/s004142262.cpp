#include <bits/stdc++.h>
using namespace std;

int main(){
	int x1, y1, x2, y2, dx, dy;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	dx = x2 - x1; dy = y2 - y1;
	printf("%d %d %d %d\n", x2 - dy, y2 + dx, x2 - dy - dx, y2 + dx - dy);
	return 0;
}
