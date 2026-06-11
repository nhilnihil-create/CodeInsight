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

int N, d = 0;
char s[105];

int main(){
	getint(N), scanf("%s", s + 1);
	for(register int i = 1; i <= N; i++) if(s[i] == 'R') d++; else d--;
	return puts(d > 0 ? "Yes" : "No"), 0;
}
