#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#define mem(u, v) memset(u, v, sizeof(u))
#define INF 0x3f3f3f3f
#define pii pair<int, int >
#define LL long long
#define mid (l + r) / 2
#define lowbit(x) x & -x
using namespace std;
const int MAXN = 1e5 + 7,  MAXM = 1e5 + 7, MAXK = 1e5 + 7;

LL gcd(LL a, LL b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		LL a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (a < b) printf("No\n");
		else if (d < b) printf("No\n");
		else if (c + 1 >= b) printf("Yes\n");
		else {
			LL g = gcd(b, d);
			if ((a - b) / g - (a - c - 1) / g >= 0) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
