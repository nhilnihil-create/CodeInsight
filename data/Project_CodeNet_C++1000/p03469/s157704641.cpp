#include <stdio.h>
int main (){
	int year, month, date;
	scanf ("%d/%d/%d", &year, &month, &date);
	year = 2018;
	printf ("%d/%.2d/%.2d\n", year, month, date);
	return 0;
}