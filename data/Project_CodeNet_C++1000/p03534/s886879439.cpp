#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int a[4];
char d[100001];
bool cmp(int a,int b){return a>b;}
int main()
{
	string s;
	cin>>s; int l=s.length();
	for (int i=0;i<l;i++)
		if (s[i]=='a') a[1]++;
		else if (s[i]=='b') a[2]++;
		else if (s[i]=='c') a[3]++;
	if (l==3) {if (a[1]==1&&a[2]==1&&a[3]==1) puts("YES"); else puts("NO"); return 0;}
	if (l==2) {if (a[1]==2||a[2]==2||a[3]==2) puts("NO"); else puts("YES"); return 0;}
	sort(a+1,a+1+3,cmp);
	for (int i=0,j=0;i<l;i++)
	{
		j=j%3+1;
		if (--a[j]<0) {puts("NO"); return 0;}
	}
	puts("YES");
	return 0;
}