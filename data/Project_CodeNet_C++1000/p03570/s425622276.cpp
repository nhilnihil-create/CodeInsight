#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 200010;
const int INF = 1e9;
int n;
int f[(1<<26)+10];
char s[N];

int main()
{
	scanf("%s", s+1); n = strlen(s+1);
	for (int i = 1; i < 1<<26; i ++){
		//if (__builtin_popcount(i) <= 1) f[i] = 1;
		f[i] = INF;
	}
	int st = 0, lst;
	for (int i = 1; i <= n; i ++){
		lst = st;
		st ^= 1<<s[i]-'a';
		f[st] = min(f[st], f[lst]+1);
		for (int j = 0; j < 26; j ++)
			f[st] = min(f[st], f[st^(1<<j)]+1);
	}
	if (!st) puts("1");
	else printf("%d\n", f[st]);
	return 0;
}