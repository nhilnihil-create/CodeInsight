#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define debug cout<<"****************"<<endl
using namespace std;
typedef long long ll;
inline void ju() {
	freopen("***.in","r",stdin);
	freopen("***.out","w",stdout);
}
inline ll rd() {
	ll x=0,f=1; char c=getchar();
	while((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main() {
	char s[10];
	scanf("%s",s+1);
	for(int i=1;s[i];++i) {
		if(s[i]=='1') s[i]='9';
		else if(s[i]=='9') s[i]='1';
	}
	printf("%s\n",s+1);
	return 0;
}
