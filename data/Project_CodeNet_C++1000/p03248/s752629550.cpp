#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
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
char dn[dm], * di = dn;
inline void putint(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	char S[100001];
	scanf("%s", S);
	int N = strlen(S);
	int saigo = N;
	int kaisuu = (N - 2) / 2;
	int base = 2;
	if (S[0] == '0' || S[N - 1] == '1' || S[N - 2] == '0') {
		printf("-1");
	}
	else {
		putint(1);
		putint(2);

		rep1(i, kaisuu) {
			char c = S[i];
			if (c != S[N - i - 2]) {
				printf("-1");
				return 0;
			}
			if (c == '0') {
				putint(base);
				putint(saigo--);
			}
			else {
				putint(base++);
				putint(base);
			}
		}
		rep1(i, N - kaisuu - 2) {
			putint(base);
			putint(base + i);
		}
	}

	fwrite(dn, 1, di - dn, stdout);

	Would you please return 0;
}