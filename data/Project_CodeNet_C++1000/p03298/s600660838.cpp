#include <bits/stdc++.h>
#define MAXN 45
#define ull unsigned long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
char s[MAXN];
unordered_map<ull,int>S;
int main(){
	int n=read();
	scanf("%s",s+1);
	for (int i=0;i<(1<<n);++i){
		ull h1=0,h2=0;
		for (int j=1;j<=n;++j){
			if (i&(1<<(j-1))) h1=h1*26ull+(ull)s[j]-'a'+1;
			else h2=h2*26ull+(ull)s[j]-'a'+1;
		}
		++S[h1+(h2<<32)];
	}
	long long ans=0;
	for (int i=0;i<(1<<n);++i){
		ull h1=0,h2=0;
		for (int j=n;j>=1;--j){
			if (i&(1<<(j-1))) h1=h1*26ull+(ull)s[j+n]-'a'+1;
			else h2=h2*26ull+(ull)s[j+n]-'a'+1;
		}
		ans+=S[h1+(h2<<32)];
	}
	printf("%lld\n",ans);
}