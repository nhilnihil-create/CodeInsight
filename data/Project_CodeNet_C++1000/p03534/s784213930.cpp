#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[3];
int main(void){
	register int i;
	cin>>s;
	for(i=0;i<s.length();++i)
		++a[s[i]-'a'];
	sort(a,a+3);
	if(a[2]==a[1]&&a[1]==a[0]||a[2]==a[1]&&a[1]-1==a[0]||a[2]-1==a[1]&&a[1]==a[0])
		puts("YES");
	else 
		puts("NO");
	return 0;
}