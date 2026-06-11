#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

int n;

int a[200005];
int l[200005];
int nxt[200005];

int memo[200005];

int dp(int pos) {
	if (pos == -1) return 0;
	if (pos == n) return 1;
	if (memo[pos] != -1) return memo[pos];
	return memo[pos] = (dp(pos+1) + dp(nxt[pos]) * (nxt[pos] > pos+1)) % MOD;
}

int main() {
	memset(memo, -1, sizeof memo);
	memset(nxt, -1, sizeof nxt);
	memset(l, -1, sizeof l);
	scanf("%d", &n);
	for (int i=0 ; i<n ; i++) {
		scanf("%d", a+i);
		if (l[a[i]] != -1) {
			nxt[l[a[i]]] = i;
		}
		l[a[i]] = i;
	}
	printf("%d\n", dp(0));
	return 0;
}