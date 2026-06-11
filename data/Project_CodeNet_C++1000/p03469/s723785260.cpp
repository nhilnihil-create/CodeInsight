#include <stdio.h>
int main () {
	char hue[11];
	scanf ("%s", &hue);
	for (int i = 0; i < 10; i++) {
		if (hue[3] >= '0' && hue[3] <= '9') {
			hue[3] = '8';
		}
	}
	printf ("%s", hue);
	return 0;
}