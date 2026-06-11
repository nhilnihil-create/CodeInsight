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
const int N = 202020;
int n;
int a[N];
int main(){
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	int mid = a[n - 1] / 2;
	int st = lower_bound(a, a + n, mid) - a;
	int l = mid, r = a[n - 1] % 2 + mid;
	pii a1 = {2e9, 2e9}, a2 = {2e9, 2e9};
	rep(i, max(0, st - 50), min(n - 1, st + 50)) {
		pii t1 = {abs(a[i] - l), a[i]}, t2 = {abs(a[i] - r), a[i]};
		a1 = min(a1, t1);
		a2 = min(a2, t2);
	}
	a1 = min(a1, a2);
	printf("%d %d\n", a[n - 1], a1.se);
	return 0;
}
