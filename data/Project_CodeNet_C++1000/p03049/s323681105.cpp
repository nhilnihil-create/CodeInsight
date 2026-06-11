#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,A,B,ans;
int flag;
char s[N];
int main(){
	flag=false;
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		int len=strlen(s+1);
		A+=s[len]=='A';
		B+=s[1]=='B';
		flag+=s[1]=='B'&&s[len]=='A';
		for(int j=1;j<len;++j){
			if(s[j]=='A'&&s[j+1]=='B')++ans;
		}
	}
	ans+=min(A,B);
	if(A==B&&flag==A&&A)--ans;
	printf("%d\n",ans);
	return 0;
}


