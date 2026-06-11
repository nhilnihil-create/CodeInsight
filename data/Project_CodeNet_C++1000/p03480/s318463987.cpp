/* - - - - - - - - - - - - - - -
	User : 		VanishD
	problem :
	Points : 	
- - - - - - - - - - - - - - - */
# include <bits/stdc++.h>
# define 	ll 		long long
using namespace std;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
int read(){
	int tmp = 0, fh = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){ if (ch == '-') fh = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9'){ tmp = tmp * 10 + ch - '0'; ch = getchar(); }
	return tmp * fh;
}
const int N = 200010;
char s[N];
int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	scanf("\n%s", s + 1);
	int l = strlen(s + 1);
	int ans = l;
	for (int i = 1; i <= l / 2; i++)
		if (s[i] != s[i + 1]) ans = min(ans, l - i);
	for (int i = 1; i <= l / 2; i++)
		if (s[l - i + 1] != s[l - i]) ans = min(ans, l - i);
	printf("%d\n", ans);
	return 0;
}
