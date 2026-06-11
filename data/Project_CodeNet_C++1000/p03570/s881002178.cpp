%:pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
    x = 0;char c = getchar();bool f = 0;
    for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
    for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if(f) x = -x;
}
const int N = 2e5 + 10 ;

// f[i] ±íÊ¾µÚiÎ»µÄ´ð°¸
// b[set] ±íÊ¾×Ó¼¯Î»setÊ±ºò×îÐ¡µÄ´ð°¸ÊÇ¶àÉÙ
int f[N], b[(1 << 26) + (1 << 4)], bit[30], n;
char str[N];
int xors = 0;
int solve(int x) {
	int ans = b[xors] + 1;
	for(int i = 0; i < 26; i ++) {
		ans = min(ans, b[xors ^ bit[i]] + 1);
	}
	b[xors] = min(b[xors], ans);
	return ans;
}


main() {
	scanf("%s", str + 1); n = strlen(str + 1);
	for(int i = 0; i <= 26; i ++) bit[i] = (1 << i);
	memset(b, 38, sizeof(b));
	xors = 0;b[0] = 0;
	for(int i = 1; i <= n; i ++) {
		str[i] -= 'a';
		xors ^= bit[str[i]];
		f[i] = solve(i);
//		cout << b[0] << "\n";
//		cout << xors << "\n";
//		cout << f[i] << "\n";
	}
	cout << f[n] << "\n";
}