#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int dm = 1 << 21;
char dn[dm], * di = dn, dt;
inline void putint(int X) {
	if (X == 0) {
		*di++ = '0';
		*di++ = ' ';
		return;
	}
	int keta = 0;
	char C[7];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = ' ';
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int M, K;
	scanf("%d %d", &M, &K);

	if (M == 0) {
		if (K == 0) printf("0 0");
		else printf("-1");
	}
	else if (M == 1) {
		if (K == 0) printf("0 0 1 1");
		else printf("-1");
	}
	else {
		if ((1 << M) <= K) {
			printf("-1");
		}
		else {
			putint(K);
			rep(i, 1 << M) {
				if (i != K) putint(i);
			}
			putint(K);
			rep(i, 1 << M) {
				if ((1 << M) - 1 - i != K) putint((1 << M) - 1 - i);
			}
			fwrite_unlocked(dn, di - dn, 1, stdout);
		}
	}
	Would you please return 0;
}