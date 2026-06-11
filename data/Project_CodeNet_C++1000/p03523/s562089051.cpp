#include <stdio.h>
#include <string.h>
char arr[100];
char aki[100] = "AKIHABARA";
int akiptr = 0;
int main() {
	scanf("%s", arr);
	int len = strlen(arr);
	for (int i = 0; i < len; ++i) {
		if (arr[i] == aki[akiptr]) {
			akiptr++;
		}
		else if (aki[akiptr] == 'A') {
			--i, akiptr++;
		}
		else {
			printf("NO");
			return 0;
		}
		if (i == len - 1 && akiptr>7) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}