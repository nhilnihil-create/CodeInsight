#include <bits/stdc++.h>
#define ri register int
using namespace std;
bitset<4000010>s;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	int n=read(),sum=0; s[0]=1;
	for (ri i=1,x;i<=n;i++){
		x=read();
		sum+=x;
		s|=(s<<x);
	}
	for (ri i=(sum+1)/2;i<=sum;i++)if(s[i])return printf("%d\n",i),0;
	return 0;
}