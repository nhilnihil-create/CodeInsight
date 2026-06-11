#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <bitset>
#define MAX_N 16005
#define MAX_R 17005
#define D 8010

using namespace std;

int n,x,y;
char s[MAX_N];
vector<int> v[2];
bitset<MAX_R> b[2];

void read()
{
	scanf("%s%d%d",s+1,&x,&y);
	n=strlen(s+1);
}

void cal_v()
{
	int k=0,cnt=0; s[n+1]='T';
	for(int i=1;i<=n+1;i++)
	{
		if(s[i]=='T') v[k].push_back(cnt),k^=1,cnt=0;
		else cnt++;
	}
}

void cal_b()
{
	b[0][v[0][0]+D]=1;
	for(int i=1;i<v[0].size();i++)
	{
		int len=v[0][i];
		b[0]=(b[0]<<len)|(b[0]>>len);
	}
	b[1][D]=1;
	for(int i=0;i<v[1].size();i++)
	{
		int len=v[1][i];
		b[1]=(b[1]<<len)|(b[1]>>len);
	}
}

void work()
{
	cal_v();
	cal_b();
	if(b[0][x+D] && b[1][y+D]) printf("Yes\n");
	else printf("No\n");
}

int main()
{
	read();
	work();
}
