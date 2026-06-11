#include<bits/stdc++.h>
#define fr(i,a,b) for(register int i = a;i <= b;++i)
#define frn(i,a,b) for(register int i = a;i >= b;--i)
#define N 2010
using namespace std;

bitset<N * N>s;
int a[N],t[N * N];
int n,sum,cnt;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0';c = getchar();}
	return f * x;
}

int main(){
	n = read();
	fr(i,1,n)a[i] = read(),sum += a[i];
	s[0] = 1;
	fr(i,1,n)s |= (s << a[i]);
	fr(i,1,sum)if(s[i])t[++cnt] = i;
	printf("%d",t[(cnt + 1) / 2]);
	return 0;
}