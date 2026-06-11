/*---------------------------------

 @Author:   Dicer
 @DateTime: 2019-01-11 19:41:55

---------------------------------*/

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define clr(s, x) memset(s, x, sizeof(s))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
inline ll readll(){ll r=0;char c=getchar();while(c<'0'||c>'9') {c=getchar();}while(c>='0'&&c<='9') {r=r*10+c-'0';c=getchar();}return r;}
inline ll qpow(ll a,ll b,ll mod){ll res=1;while(b){if(b&1)res = (res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
inline ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
const double eps = 1e-8;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int MAXN = 1e5+7;
const int MAXM = 1e5+7;

int main(int argc, char const *argv[])
{
	int n, h, w;
	cin >> n >> h >> w;
	cout << (n-h+1)*(n-w+1) << endl;
	return 0;
}