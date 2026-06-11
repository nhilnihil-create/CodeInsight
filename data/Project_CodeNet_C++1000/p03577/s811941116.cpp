#include<bits/stdc++.h>
using namespace std;
int n;
char a[55];
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	a[n-7]=0;
	puts(a+1);
	return 0;
}