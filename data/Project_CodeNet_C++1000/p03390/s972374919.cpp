#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 600006

int test;
ll a, b;

void solve(int itest){
	cin >> a >> b;
	if(a > b) swap(a, b);
	if(a == b) {
		cout << a + a - 2 << endl;
		return;
	}
	ll res = a - 1;
	ll l = a, r = b, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(mid * mid < a * b) l = mid + 1;
		else r = mid;
	}
	l--;
	res += l - a + l - 1;
	if(l * (l + 1) < a * b) res++;
	cout << res << endl;
}

int main(){
	srand(1412);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	cin >> test;
	For(itest, 1, test){
		solve(itest);
	}

    return 0;
}
