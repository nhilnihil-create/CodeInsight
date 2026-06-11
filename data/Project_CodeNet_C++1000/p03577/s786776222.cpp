#include<bits/stdc++.h>
using namespace std;
char c[5010];
int main()
{
	scanf("%s",c+1);
	int l=strlen(c+1);
	for(int i=1;i<=l-8;i++)
	printf("%c",c[i]);
	return 0;
}