#include <bits/stdc++.h>

using namespace std;

#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)

#define LL long long
#define mp make_pair
#define pb push_back

#define K 560001

int n;

int a[K], b[K];

LL ta, tb;
LL allow;

int main() {
	scanf("%d", &n);
	
	FOE(i, 1, n) scanf("%d", &a[i]);
	FOE(i, 1, n) scanf("%d", &b[i]);
	
	FOE(i, 1, n) {
		if (a[i] >= b[i]) {
			ta += (a[i] - b[i]);
		} else {
			ta += (a[i] - b[i]) / 2;	
		}
	}
	
	if (ta <= 0) {
		puts("Yes");	
	} else {
		puts("No");	
	}
}