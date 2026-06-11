#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define cs const 
#define fr first 
#define se second
#define ls (now<<1)
#define mid ((l+r)>>1)
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define low(i) (i&(-i))
#define par pair<int,int>
#define cn(x) memset(x, 0, sizeof(x))
#define rep(i, x, y) for(int i=x; i<=y; ++i)
#define sep(i, x, y) for(int i=x; i>=y; --i)
#define fore(i, x) for(int i=fir[x]; i; i=nex[i])

cs int G = 3;
cs int N = 2e5;
cs int ff = 1e6 + 15;
cs int inf = 1e18 + 1;
cs int base = 2333;
cs int M = 998244353;
cs double eps = 1e-14;

int n, A[ff];
void init()
{
	cin >> n;
	rep(i, 1, n) scanf("%lld", &A[i]);
	sort(A + 1, A + 1 + n);
	int mn = 1;
	rep(i, 2, n - 1)
		if(min(A[mn], A[n] - A[mn]) < min(A[i], A[n] - A[i])) mn = i;
	cout << A[n] << " " << A[mn];
}
signed main()
{
	int Ts = 1;
	while(Ts--)
		init();
}