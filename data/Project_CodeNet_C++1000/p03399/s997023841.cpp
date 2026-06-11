#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int main ()
{
	int a,b,c,d;
	scanf("%i%i%i%i",&a,&b,&c,&d);
	int r=0;
	r+=min(a,b);
	r+=min(c,d);
	printf("%i",r);
	return 0;
}
