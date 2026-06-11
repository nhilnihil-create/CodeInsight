#include<stdio.h>
int main()
{
	int n,t,a,h,i,in;
	float temp, dif, tmin = 10000;
	scanf("%d %d %d", &n, &t, &a);
	for(i=0; i<n; i++)
	{
		scanf("%d", &h);
		temp = t-h*.006;
		dif = a-temp;
		if(dif<0) dif = -dif;
		if(dif<tmin)
		{
			tmin = dif;
			in = i+1;
		}
	}
	printf("%d\n", in);
	return 0;
}