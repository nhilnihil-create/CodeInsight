#include<bits/stdc++.h>
int read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	int k=1,kk=0;if (c=='-')c=getchar(),k=-1;
	while (c>='0'&&c<='9')kk=kk*10+c-'0',c=getchar();return k*kk;
}using namespace std;
char s[1000000];
int f[10],l;
int main(){
	scanf("%s",s);l=strlen(s);for (int i=0;i<l;i++)f[s[i]-'a']++;
	if (max(f[0],max(f[1],f[2]))<=1+min(f[0],min(f[1],f[2])))puts("YES");else puts("NO");
}
