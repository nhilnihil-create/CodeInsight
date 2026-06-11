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

int N, Q, ans; char str[200005], tmp[5];
struct Spell {char c; int d;} sp[200005];

inline bool check_l(int pos){
	for(register int i = 1; i <= Q; i++)
		if(sp[i].c == str[pos] && (pos += sp[i].d) < 1) return 1;
	return 0;
}

inline bool check_r(int pos){
	for(register int i = 1; i <= Q; i++)
		if(sp[i].c == str[pos] && (pos += sp[i].d) > N) return 1;
	return 0;
}

int main(){
	getint(N), getint(Q), scanf("%s", str + 1);
	for(register int i = 1; i <= Q; i++){
		scanf("%s", tmp), sp[i].c = *tmp;
		scanf("%s", tmp), sp[i].d = *tmp == 'L' ? -1 : 1;
	}
	int l = 0, r = N;
	while(l < r){
		const int mid = l + r + 1 >> 1;
		if(check_l(mid)) l = mid;
		else r = mid - 1;
	}
	ans = l, l++, r = N + 1;
	while(l < r){
		const int mid = l + r >> 1;
		if(check_r(mid)) r = mid;
		else l = mid + 1;
	}
	ans += N - l + 1;
	return printf("%d\n", N - ans), 0;
}