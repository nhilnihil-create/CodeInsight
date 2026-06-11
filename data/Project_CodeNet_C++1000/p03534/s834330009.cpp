#include<bits/stdc++.h>
using namespace std;

char s[(int)1e5+10];
int a[4];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		a[s[i]-'a']++;
	}
	sort(a,a+3);
	if(a[2]-a[0]<=1)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}




}
