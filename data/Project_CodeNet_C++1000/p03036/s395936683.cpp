#include<stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int r, d, x;
	scanf("%d %d %d", &r, &d, &x);

	for (int i = 1; i <= 10; i++){
		x = r*x - d;
		printf("%d\n", x);
	}
}