#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int a,b;
	scanf("%i%i",&a,&b);
	if(b<a)	printf("%i",a-1);
	else printf("%i",a);
	return 0;
}
