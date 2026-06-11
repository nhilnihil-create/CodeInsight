#include<bits/stdc++.h>
using namespace std;
char s[100100];
int a[100];
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)
		a[s[i]-'a']++;
	int c=min(a[0],min(a[1],a[2]));
	for(int i=0;i<3;++i)
		if((a[i]-=c)>=2)return puts("NO"),0;
	puts("YES");
}