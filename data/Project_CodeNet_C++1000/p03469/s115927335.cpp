#include <stdio.h>

int main() {
	int year, month, day;
	scanf ("%d/%d/%d", &year, &month, &day);
	
	if (year != 2018){
		year = 2018;
	}
	else {
		year = 2018;
	}
	printf ("%d/%02d/%02d", year, month, day);
	return 0;
}