#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	char top[3];
	int num = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%c", &top[i]);
		if (top[i] == 'o') num++;
	}
	printf("%d\n", 700 + num * 100);

	return 0;
}
