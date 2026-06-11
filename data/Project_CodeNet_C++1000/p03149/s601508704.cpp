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

int cnt[10];

int main(){
	for(register int i = 1, v; i <= 4; i++) getint(v), cnt[v]++;
	return puts(cnt[1] && cnt[9] && cnt[7] && cnt[4] ? "YES" : "NO"), 0;
}