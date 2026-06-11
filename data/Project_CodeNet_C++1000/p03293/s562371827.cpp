#include<stdio.h>
#include<string.h>
int main()
{
	int i,t,j,s=0;
	char S[210],T[210];
	char d;
	scanf("%s",S);
	scanf("%s",T);
	t=strlen(S);
	for(i=0;i<t;i++)
	{
		if(strcmp(S,T)==0)
		{
			s=1;
			break;
		}
		d=S[t-1];
		for(j=t-2;j>=0;j--)
		{
			S[j+1]=S[j];
		}
		S[0]=d;
	}
	if(s==0)
		printf("No");
	else
		printf("Yes");
	return 0;
}