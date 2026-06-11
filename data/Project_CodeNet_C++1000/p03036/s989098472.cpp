#include <cstdio>
using namespace std;

int main() {
	int r, D, x;
	scanf("%d %d %d", &r, &D, &x);
	
	for(int i = 0; i < 10; i++) {
		x = r * x - D;
		printf("%d\n", x);
	}
	
	return 0;
}