#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)
#define il inline
#define LL long long
#define ULL unsigned LL
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
#define fi first
#define se second
using namespace std;
il int read() {
	int res = 0,f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -f; ch = getchar();}
	while (isdigit(ch)) {res = res*10+ch-'0'; ch = getchar();} return res*f;
}
namespace qiqi {
	const int N = 2e5+5; int n,a[N],s[N],top;
	il bool check(int k) {top = 0; rep(i,2,n) if (a[i] <= a[i-1]) {while (a[i] < s[top]) --top; s[++top] = a[i]; while (top >= k && s[top] == s[top-k+1]) --s[top -= k-1];} return s[1] > 0 || !top;}
	void main() {n = read(); rep(i,1,n) a[i] = read(); bool flg = 1; rep(i,2,n) flg &= a[i] > a[i-1]; if (flg) {puts("1"); return;} int l = 2,r = 2e5,mid; while (l <= r) check(mid = (l+r)/2) ? r = mid-1 : l = mid+1; printf("%d\n",l);}
}
int main() {
	qiqi::main(); return 0;
}