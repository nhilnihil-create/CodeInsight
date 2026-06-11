#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int w=8000;
int n,x,y;bool f[2][2][20000];
char s[8010];
int main()
{
	scanf("%s %d %d",s+1,&x,&y);x+=w;y+=w;
	n=strlen(s+1);int t=0,i=1;
	while(i<=n&&s[i]=='F') t++,i++;
	int p=0,q=0;f[0][0][w+t]=true;f[1][0][w]=true;
	while(i<=n)
	{
		i++;p^=1;q^=p;
		int sum=0;
		while(i<=n&&s[i]=='F') sum++,i++;
		for(int i=w-n;i<=w+n;i++) f[p][q][i]=f[p][q^1][i-sum]|f[p][q^1][i+sum];
	}
	if(p==1&&f[0][q^1][x]&&f[1][q][y]||p==0&&f[0][q][x]&&f[1][q][y]) puts("Yes");
	else puts("No");
}