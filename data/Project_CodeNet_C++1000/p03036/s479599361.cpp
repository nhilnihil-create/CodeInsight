#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
	int r, D, x;
	scanf("%d %d %d", &r, &D, &x);
    for (int i=0; i < 10; i++) {
        int x1;
        x1 = r * x -D;
        printf("%d\n", x1);
        x = x1;
    }
    
}