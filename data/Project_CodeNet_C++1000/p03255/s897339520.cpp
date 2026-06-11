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
#include <queue>
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
const int VAL = (int)1e9;
int n, m;
int a[N+5];
void input(){
	scanf("%d %d", &n, &m);
	rep(i, 0, n) scanf("%d", &a[i]);
}
ll calc(int x){
	ll res = 0;
	int cnt = x, cur = -2;
	res = n*(ll)m*2;
	per(i, 0, n){
		res += a[i]*5LL;
		if(cur >= 0) res += -m + cur*(ll)a[i];
		if(--cnt == 0) cnt = x, cur += 2;
	}
//	printf("x %d  res %lld\n", x, res);
	return res;
}
void Main(){
	input();
	int L = 1, R = n;
	ll ans = linf;
	while(L < R){
		int mid1 = (L+R)/2;
		int mid2 = mid1+1;
		ll tmp1 = calc(mid1);
		ll tmp2 = calc(mid2);
		if(tmp1 < tmp2) ans = tmp1, R = mid1;
		else ans = tmp2, L = mid2;
	}
	cout << ans << endl;
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
