#include <stdio.h>

int main ()
{
 
 	int i;
 	int a, b;
 	scanf("%d %d", &a, &b);
 	
	char str [a + b +1];
 	scanf("%s", &str);

 	int ans = 0;
 	
	for(i = 0; i<a+b+1; i++)
 	{
  		if (i != a) 
  		{
  		
			if (str[i]>='0' && str[i]<='9')
			{
  			 	ans++;
  			}
 		
		}
 		
		else if (str[i] == '-')
		{
 			 ans++;
 		}
 	}
 	
	if (ans == a + b + 1)
	{
  		printf("Yes");
 	} 
 	
	 else 
	 {
  		printf("No");
	 }
 
 return 0;
}