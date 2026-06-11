#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n; char s[110];
	cin>>n;
	scanf("%s",s+1);
	int r=0,b=0;
	for (int i=1;i<=n;i++) 
		if (s[i]=='R') r++; else b++;
	if (r>b) puts("Yes"); else puts("No");
	return 0;
}