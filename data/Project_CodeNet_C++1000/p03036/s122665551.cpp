#include<cstdio>
using namespace std;

int main(void) {
	int r, D, x2000;
	scanf("%d %d %d", &r, &D, &x2000);
	int nextX = x2000;
	for (int i = 0; i < 10; i++) {
		nextX = r * nextX - D;
		printf("%d\n", nextX);
	}
	return 0;
}
