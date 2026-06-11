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

int deg[5];

int main(){
	for(register int i = 1; i <= 3; i++){
		int u, v; getint(u), getint(v);
		deg[u]++, deg[v]++;
	}
	for(register int i = 1; i <= 4; i++)
		if(deg[i] != 1 && deg[i] != 2) return puts("NO"), 0;
	return puts("YES"), 0;
}
