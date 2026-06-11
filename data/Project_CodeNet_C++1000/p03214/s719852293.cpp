#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, a[105];

int main(){
	getint(N); int avg = 0, ans = 0;
	for(register int i = 0; i < N; i++) getint(a[i]), avg += a[i], a[i] *= N;
	for(register int i = 1; i < N; i++) if(abs(a[i] - avg) < abs(a[ans] - avg)) ans = i;
	return printf("%d\n", ans), 0;
}