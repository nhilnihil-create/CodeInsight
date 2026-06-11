#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i, a, b) for(int i = a, i##_END_ = b; i < i##_END_; ++i)
#define per(i, a, b) for(int i = (b)-1, i##_BEGIN_ = a; i >= i##_BEGIN_; --i)
typedef long long ll;
typedef double db;
const int inf = (int)1e9;
const ll linf = (ll)1e18;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
template<class T>
inline void read(T &x){
	char c; x = 0;
	bool neg = false;
	while(c = getchar(), c!='-' && (c<'0'||c>'9'));
	if(c == '-') neg = true, c = getchar();
	do x = (x*10) + (c^48);
	while(c = getchar(), c>='0'&&c<='9');	
	if(neg) x = -x;
}
template<class T>
inline void print(T x){
	if(x == 0){ putchar('0'); return;}
	if(x < 0){ putchar('-'); x = -x;}
	static char stk[30]; int top = 0;
	while(x) stk[++top] = x%10^48, x /= 10;
	while(top) putchar(stk[top--]);
}
#ifdef Leefir
	#define ast(x) assert(x)
	#define dig(...) fprintf(stderr, __VA_ARGS__)
#else
	#define ast(x) ;
	#define dig(...) ;
#endif

namespace Program{

const int N = (int)2e5;
const int M = (int)2e5;
int n, m;
char str[N+5];
vi vec[N+5];
int cnt[N+5][2];
void input(){
	scanf("%d %d", &n, &m);
	scanf("%s", str);
	rep(i, 0, n) str[i] -= 'A';	
	rep(i, 0, n) cnt[i][0] = cnt[i][1] = 0;
	rep(i, 0, n) vec[i].clear();
	rep(i, 0, m){
		int x, y; scanf("%d %d", &x, &y);
		--x; --y;
		cnt[x][str[y]]++;
		cnt[y][str[x]]++;
		vec[x].pb(y);
		vec[y].pb(x);
	}
}
bool del[N+5];
void solve(){
	rep(i, 0, n) del[i] = false;
	static int que[N+5];
	int qh = 0, qt = 0;
	rep(i, 0, n) if(cnt[i][0] == 0 || cnt[i][1] == 0) que[qt++] = i, del[i] = true;
	while(qh < qt){
		int u = que[qh++];
		rep(i, 0, sz(vec[u])){
			int v = vec[u][i];
			cnt[v][str[u]]--;
			if(cnt[v][0] == 0 || cnt[v][1] == 0){
				if(!del[v]) que[qt++] = v, del[v] = true;
			}
		}
	}
	bool ok = false;
	rep(i, 0, n) if(del[i] == false) ok = true;
	if(ok) puts("Yes");
	else puts("No");
}
void Main(){
	input();
	solve();
}

} //namespace Program
int main(){
#ifdef Leefir
	dig("**********define Leefir***********\n");
#endif
	srand(time(NULL));
	
	Program::Main();
	
	return 0;
}
