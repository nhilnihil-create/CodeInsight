#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(pos, len) for(int pos=0;pos<len;pos++)
#define repp(pos, len) for(int pos=1;pos<=len;pos++)

#define INF 987654321
#define IINF 2987654321987654321
#define MOD 998244353

inline void no() {
	printf("-1\n");
	exit(0);
}

const int MAXN = 1e5 + 50;
char s[MAXN];

int main() {
	scanf("%s", s+1);
	int n = strlen(s+1);

	if(s[n] == '1' || s[1] == '0') no();
	for(int i = 1; i <= n-1; i++)
		if(s[i] != s[n-i]) no();

	vector<int> v;
	v.push_back(n);
	for(int i = n/2; i >= 1; i--)
		if(s[i] == '1') v.push_back(i);

	int cur = 1, id = 1;
	for(int i = 0; i < (int)v.size()-1; i++) {
		int d = v[i] - v[i+1];
		rep(t, d) printf("%d %d\n", cur, ++id);
		cur = id;
	}
}