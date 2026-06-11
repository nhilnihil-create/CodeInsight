#include <stdio.h>
#include <string.h>
 
 
int main ()
{
	int a, b, ctr=0;
	char kode[100];
	
	scanf ("%d %d",&a,&b);
	scanf ("%s",kode);
	
		
	int i = 0;
	while (i<=strlen(kode))
	{
		i++;
		if (kode[i] == '-')
		{
		ctr++;
		}
	}
	
	if (ctr>1) 
	{
		printf ("No");
		return 0;
	}
	
	if (kode [a] != '-')
	{
			printf ("No");
			return 0;
	}
	
	
	printf ("Yes");
	
return 0;	
}