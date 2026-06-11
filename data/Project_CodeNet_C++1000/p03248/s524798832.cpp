#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define biu (puts("-1"), exit(0))  // manshinsoui
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int n; char s[100005];

int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	if(s[1] == '0' || s[n] == '1') biu;
	for(register int i = 1; i < n - i; i++) if(s[i] != s[n - i]) biu;
	for(register int i = 2, cur = 0; i <= n; i++) if(s[i] == '1')
		for(; cur < i; cur++) if(cur) printf("%d %d\n", cur, i);
	return printf("%d %d\n", n - 1, n), 0;
}