#include <stdio.h>

int main(){
	int year;
	int month;
	int day;
	
	scanf("%d /%d /%d", &year, &month , &day);
	printf("%d/%0.2d/%0.2d", ++year , month , day);
	
	return 0;
}
