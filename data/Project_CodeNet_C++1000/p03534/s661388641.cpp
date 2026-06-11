#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int iinf = 1 << 29;
const long long linf = 1ll << 61;

#define modp(x, y) (((y) + (x) % (y)) % (y))
template<typename T> inline T gcd(T x, T y) { if(x < y) swap(x, y); T mod = x % y; if(mod == 0) return y; return gcd(y, mod); }
template<typename T> inline T lmc(T x, T y) { return x / gcd(x, y) * y; }

char S[100100];

int main(int argc, char* argv[])
{
	scanf("%s", S);
	int l = strlen(S);

	int count[3] = {};
	for(int i = 0; i < l; i++) count[S[i] - 'a']++;
	int m = iinf;
	for(int i = 0; i < 3; i++) m = min(m, count[i]);
	bool flag = true;
	for(int i = 0; i < 3; i++)
		if(count[i] > m + 1) flag = false;
	printf("%s\n", flag ? "YES" : "NO");

	return 0;
}
