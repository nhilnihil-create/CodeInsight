#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int f[1<<26],d[N];
char s[N];
int main()
{
	memset(f,0x3f,sizeof f);
	scanf("%s",s);
	int m=0,t;f[0]=0;
	for(int i=0;s[i];i++)
	{
		m^=1<<(s[i]-'a');
		t=f[m]+1;
		for(int j=0;j<26;j++) 
			t=min(t,f[m^(1<<j)]+1);
		f[m]=min(f[m],t);
	}
	printf("%d\n",t);
	return 0;
}