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
const int N = 100010;
int n, num[N], v[N], ans, now[N], hav[N * 2];
bool check(int x){
	ll tot = 1ll * n * (n + 1) / 2, sum = 0;
	memset(hav, 0, sizeof(hav));
	for (int i = 1; i <= n; i++)
		if (num[i] >= x)
			now[i] = 1; else now[i] = -1;
	int delt = 100005, cnt = 0;
	for (int i = 1; i <= n; i++){
		if (now[i] == 1){
			delt--;
			cnt = cnt + hav[delt] + 1;
			hav[delt + 1] += 1;
		}
		else {
			cnt = cnt - hav[delt];
			delt++;
			hav[delt - 1] += 1;
		}
		sum = sum + cnt;
	}
	if (sum >= (tot + 1) / 2)
		return true;
		else return false;
}
int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++)
		num[i] = v[i] = read();
	sort(v + 1, v + n + 1);
	int pl = 1, pr = n;
	while (pl <= pr){
		int mid = (pl + pr) / 2;
		if (check(v[mid]) == true)
			ans = v[mid], pl = mid + 1;
			else pr = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
