#include<cstdio>
#include<cctype>
inline char rdc(){
	char c=getchar();
	while(!isupper(c))c=getchar();
	return c;
}
const int N=200050;
char s[N],t[N];
int n,q;
bool opt[N];
inline bool check1(int p){
	for(int i=0;i<q;++i)if(s[p]==t[i])if(opt[i])if(!--p)return 1;
	else;
	else ++p;
	return 0;
}
inline bool check2(int p){
	for(int i=0;i<q;++i)if(s[p]==t[i])if(opt[i])--p;
	else if(++p>n)return 1;
	return 0;
}
int main(){
	int i,l=1,r,m,s1=0,s2;
	char c;
	scanf("%d%d%s",&n,&q,s+1);
	s2=(r=n)+1;
	for(i=0;i<q;++i){t[i]=rdc();opt[i]=rdc()=='L';}
	while(l<=r){
		m=l+r>>1;
		if(check1(m))l=(s1=m)+1;
		else r=m-1;
	}
	l=s1+1;r=n;
	while(l<=r){
		m=l+r>>1;
		if(check2(m))r=(s2=m)-1;
		else l=m+1;
	}
	printf("%d\n",s2-s1-1);
	return 0;
}