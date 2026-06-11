#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int main(void) 
{
	int N;
	char a[110];
	int countr = 0;
	int countb = 0;
	scanf("%d", &N);
	scanf("%s", a);
	for (int i = 0; i < N; i++) {
		if (a[i] == 'R') {
			//printf("%c", a[i]);
			countr++;
		}
		else{
			//printf("%c", a[i]);
			countb++;
		}
		//printf("%d %d\n", countr, countb);
	}

	if (countr > countb) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}

