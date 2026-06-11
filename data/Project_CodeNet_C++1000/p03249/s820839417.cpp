# include <bits/stdc++.h>
using namespace std;
namespace Base{
	# define mr make_pair
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	template<typename T> void read(T &x){
    	x = 0; int fh = 1; double num = 1.0; char ch = getchar();
		while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
		while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
	    if (ch == '.'){
	    	ch = getchar();
	    	while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
		}
		x = x * fh;
	}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

const int N = 100010;
struct Edge{
	int data, next;
}e[N * 2];
struct Node{
	int id; ll num;
}p[N];
int n, size[N], eu[N], ev[N], head[N], place, cnt;
ll num[N], dis;
void build(int u, int v){
	e[++place].data = v; e[place].next = head[u]; head[u] = place;
}
void dfs(int x, int fa, int di){
	dis += di;
	for (int ed = head[x]; ed != 0; ed = e[ed].next)
		if (e[ed].data != fa)
			dfs(e[ed].data, x, di + 1);
}
void error(){
	printf("-1\n");
	exit(0);
}
bool cmp(Node x, Node y){
	return x.num < y.num;
}
int main(){
	read(n);
	for (int i = 1; i <= n; i++){
		read(num[i]), size[i]++;
		p[i].num = num[i];
		p[i].id = i;
	}
	sort(num + 1, num + n + 1);
	sort(p + 1, p + n + 1, cmp);
	for (int i = n; i >= 1; i--){
		ll tmp = num[i] - (n - 2 * size[i]);
		if (tmp >= num[i]) continue;
		ll id = lower_bound(num + 1, num + n + 1, tmp) - num;
		if (num[id] == tmp){
			build(id, i); build(i, id);
			eu[++cnt] = id, ev[cnt] = i;
			size[id] += size[i];
		}
		else error();
	}
	dfs(1, 0, 0);
	if (dis != num[1]) error();
	for (int i = 1; i < n; i++)
		printf("%d %d\n", p[eu[i]].id, p[ev[i]].id);
	return 0;
}

