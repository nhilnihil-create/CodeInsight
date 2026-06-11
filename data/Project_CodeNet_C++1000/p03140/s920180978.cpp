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

int N, ans = 0;
char A[105], B[105], C[105];

int main(){
	getint(N), scanf("%s%s%s", A + 1, B + 1, C + 1);
	for(register int i = 1; i <= N; i++){
		if(A[i] == B[i] && B[i] == C[i]) continue;
		else if(A[i] == B[i] || B[i] == C[i] || C[i] == A[i]) ans++;
		else ans += 2;
	}
	return printf("%d\n", ans), 0;
}