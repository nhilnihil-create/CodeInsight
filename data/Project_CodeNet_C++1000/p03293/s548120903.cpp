#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
	char s[150],t[150],m[150];
	int i,j,k;
	scanf("%s %s",s,t);
	strcpy(m,s);
	
	k = strlen(s);
	int l = 2;
	while(1)
	{
		j = s[k-1];
		for(i=1;i<k;i++)
		{
			s[k-i] = s[k-i-1];
			
		}
		s[0] = j;
		
		if(strcmp(s,t) == 0) {
			printf("Yes");
			break;
		}
		else if(strcmp(s,m) == 0)
		{
			printf("No");
			break;
		}
		 
	}
	
}