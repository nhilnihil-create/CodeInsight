#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef double LF;

#define clr(x, y) memset(x, y, sizeof(x))

inline LL read(){
	LL r = 0, z = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') z = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){r = r * 10 + ch - '0'; ch = getchar();}
	return r * z;
}

LL n, a, b, c;

void work(){
	n = read();
	while(n --){
		a = read(), b = read();
		if(a == b) printf("%lld\n", 2 * a - 2);
		else if(a + 1 == b) printf("%lld\n", 2 * a - 2);
		else {
			c = sqrt(a * b); if(c * c == a * b) c --;
			if(c * (c + 1) < a * b) printf("%lld\n", 2 * c - 1);
			else printf("%lld\n", 2 * c - 2);
		}
	}
}

int main(){
	work();
	return 0;
}