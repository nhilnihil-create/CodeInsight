#include <stdio.h>
 
int main() {
 
int year, month, date;
 
scanf("%d/%d/%d", &year, &month, &date);
 
int yearFixed = year + 1;
 
printf("%d/%.2d/%.2d", yearFixed, month, date);
    return 0;
}