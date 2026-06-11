#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, Q, k;
char S[1000005];

int main(){
	getint(N), scanf("%s", S), getint(Q);
	while(Q--){
		getint(k); ll D = 0, M = 0, DM = 0, ans = 0;
		for(register int i = 0; i < N; i++){
			if(i >= k){
				if(S[i - k] == 'D') D--, DM -= M;
				else if(S[i - k] == 'M') M--;
			}
			if(S[i] == 'D') D++;
			else if(S[i] == 'M') M++, DM += D;
			else if(S[i] == 'C') ans += DM;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
