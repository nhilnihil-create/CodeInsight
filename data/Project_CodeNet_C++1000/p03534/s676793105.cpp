#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int bin[3];
char s[100000+10];
int main(){
	cin>>s;
	for(int i=0;i<strlen(s);i++)
		bin[s[i]-'a']++;
	int Min=min(bin[0],min(bin[1],bin[2]));
	bin[0]-=Min;
	bin[1]-=Min;
	bin[2]-=Min;
	if(bin[1]>=2 || bin[2]>=2 || bin[0]>=2)printf("NO\n");
	else printf("YES\n");
	return 0;
}