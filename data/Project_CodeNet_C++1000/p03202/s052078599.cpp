#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
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
auto rd=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
//const u32 P=;
//u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//u32 sum(u32 a, u32 b) {return inc(a, b);}
//u32 dif(u32 a, u32 b) {return dec(a, b);}

const int N=2e5;
int n, a[N];
bool chk(int s) {
	std::vector<std::pair<int, int>> d;
	for(int i=1, j; i<n; ++i)
		if(a[i]<=a[i-1]) {
			while(!d.empty()&&d.back().first>a[i]) d.pop_back();
			for(j=a[i]; !d.empty()&&d.back().first==j&&++d.back().second==s; --j) d.pop_back();
			if(j==0) return false;
			if(d.empty()||d.back().first!=j) d.emplace_back(j, 1);
		}
	return true;
}
int main() {
	bool ascent=true;
	n=rd();
	std::generate(a, a+n, rd);
	for(int i=1; i<n; ++i) ascent&=a[i-1]<a[i];
	if(ascent) {
		puts("1");
	} else {
		int l=2, r=n;
		while(l<r) {
			int s=(l+r)/2;
			if(chk(s)) r=s; else l=s+1;
		}
		printf("%d\n", l);
	}
	return 0;
}
