#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
char s[20];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0;
	for(int i=1;i<=n;++i){
		cnt+=(s[i]=='o');
	}
	printf(15-n+cnt>=8?"YES\n":"NO\n");
	return 0;
}

