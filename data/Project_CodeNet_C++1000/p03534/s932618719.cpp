#include<bits/stdc++.h>
using namespace std;
int read()
{
    char s;
    int k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
    if(s==EOF)exit(0);
    if(s=='-')base=-1,s=getchar();
    while(s>='0'&&s<='9')
    {
        k=k*10+(s-'0');
        s=getchar();
    }
    return k*base;
}
void write(int x)
{
    if(x<0)
    {
        putchar('-');
        write(-x);
    }
    else
    {
        if(x/10)write(x/10);
        putchar(x%10+'0');
    }
}
char ch[100100];
int n,s[500];
int main()
{
	scanf("%s",ch+1);
	n=strlen(ch+1);
	if (n<=1)
	{
		printf("YES");
		return 0;
	}
	if (n==2)
	{
		if (ch[1]!=ch[2]) printf("YES"); else printf("NO");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		s[ch[i]-'a']++;
	}
	int max1=s[0],min1=s[0];
	max1=max(max1,s[1]);max1=max(max1,s[2]);
	min1=min(min1,s[1]);min1=min(min1,s[2]);
	if (max1-min1>1)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}