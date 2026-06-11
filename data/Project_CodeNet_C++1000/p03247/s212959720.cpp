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

void construct(int m, int x, int y) {
	if(m==0) {
		puts("");
		return;
	}
	int d=1<<--m;
	if(abs(x)>abs(y)) {
		if(x>0) printf("R"), construct(m, x-d, y);
		if(x<0) printf("L"), construct(m, x+d, y);
	} else {
		if(y>0) printf("U"), construct(m, x, y-d);
		if(y<0) printf("D"), construct(m, x, y+d);
	}
}
int main() {
	int n=rd(), max=0;
	std::vector<int> x(n), y(n);
	for(int i=0; i<n; ++i) {
		x[i]=rd(), y[i]=rd();
		cmax(max, abs(x[i])+abs(y[i]));
	}
	for(int i=1; i<n; ++i)
		if((x[i]^y[i]^x[0]^y[0])&1) {
			puts("-1");
			return 0;
		}
	if((x[0]^y[0])&1) {
		puts("31");
		for(int i=31; i--; ) printf("%d%c", 1<<i, " \n"[!i]);
		for(int i=0; i<n; ++i) construct(31, x[i], y[i]);
	} else {
		printf("32\n1");
		for(int i=31; i--; ) printf(" %d", 1<<i);
		printf("\n");
		for(int i=0; i<n; ++i) {
			printf("R");
			construct(31, x[i]-1, y[i]);
		}
	}
	return 0;
}
