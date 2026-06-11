#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
inline int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
inline int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
inline int mul(int a, int b) {return 1ll * a * b % P;}
inline int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
const int N = 101010, M = N + N;
int n;
int a[N], b[N];
int c[M];
ll m;
void upd(int x) {
	x += N;
	for(; x < M; x += x & -x)
		c[x]++;
}
int qry(int x) {
	x += N;
	int res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res;
}
bool gao(int x) {
	rep(i, 1, n + 1) b[i] = a[i] >= x ? 1 : -1;
	rep(i, 1, n + 1) b[i] += b[i - 1];
	ll cnt = 0;
	memset(c, 0, sizeof(c));
	upd(0);
	rep(i, 1, n + 1) {
		cnt += qry(b[i]);
		upd(b[i]);
	}
	return cnt >= (m + 1) / 2;
}
int main(){
	scanf("%d", &n);
	rep(i, 1, n + 1) scanf("%d", a + i);
	int lo = 1, hi = 1e9 + 1;
	m = 1ll * n * (n + 1) / 2;
	while(lo + 1 < hi) {
		int mid = lo + hi >> 1;
		gao(mid) ? lo = mid : hi = mid;
	}
	printf("%d\n", lo);
	return 0;
}
