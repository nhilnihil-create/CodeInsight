#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
char s[maxn];
int main(){
	cin>>s;
	int n=strlen(s);
	int a[4];
	a[1]=a[2]=a[3]=0;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='a')a[1]++;
		if (s[i]=='b')a[2]++;
		if (s[i]=='c')a[3]++;
	}
	sort(a+1,a+1+3);
	if (a[3]-a[1]<=1 && a[2]-a[1]<=1) puts("YES");
	else puts("NO");
}