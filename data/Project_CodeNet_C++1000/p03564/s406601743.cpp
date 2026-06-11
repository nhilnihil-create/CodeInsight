//h
#include <stdio.h>

int main(){
	int n, k, result = 1;
	
	scanf ("%d %d", &n, &k);
	for (int i = 0; i<n; i++)
	{
		if (result*2 < result +k)
		{
			result = result*2;
		}
		else if (result*2 > result +k)
		{
			result= result+k;
		}
		else if (result*2 == result+k)
		{
			result = result+k;
		}
	}
	printf ("%d\n",result);
	return 0;
}