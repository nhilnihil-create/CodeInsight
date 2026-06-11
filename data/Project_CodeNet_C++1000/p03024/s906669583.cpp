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

int cnt = 0;
char S[18];

int main(){
	scanf("%s", S);
	for(register char *it = S; *it != '\0'; it++) if(*it == 'x') cnt++;
	return puts(cnt <= 7 ? "YES" : "NO"), 0;
}