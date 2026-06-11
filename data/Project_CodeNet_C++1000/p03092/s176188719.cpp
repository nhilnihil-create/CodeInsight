#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;

const int N=5050;
int n, a, b, p[N];
s64 f[N];
int main() {
	n=rd(), a=rd(), b=rd();
	for(int i=1; i<=n; ++i) p[i]=rd();
	p[n+1]=n+1;
	for(int i=1; i<=n+1; ++i) {
		s64 sum=0;
		f[i]=1e18;
		for(int j=i; j--; ) {
			if(p[j]<p[i]) cmin(f[i], f[j]+sum);
			sum+=p[j]<p[i]?b:a;
		}
	}
	printf("%lld\n", f[n+1]);
	return 0;
}
