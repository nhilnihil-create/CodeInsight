#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define FB(i,a,b) for(ll i=a;i>=b;i--)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define ND second
#define ST first
using namespace std;
const int N=1e5+5;
const ll M=1e9+7;

ll A[N];
ll H[N];

ll f_P(ll a,ll w);

int main()
{
	ll n;
	scanf("%lld",&n);
	F(i,1,n) scanf("%lld",&A[i]);

	H[0]=0;
	F(i,1,n) H[i]=(H[i-1]+f_P(i+1,M-2))%M;

	ll res=0;
	ll fact=1;
	F(i,1,n) res=(res+(((H[i-1]+H[n-i]+1)%M)*A[i])%M)%M, fact=(fact*i)%M;
	res=(res*fact)%M;
	printf("%lld\n",res);
}
///////
ll f_P(ll a,ll w)
{
	if(w==0) return 1;

	ll k=f_P(a,w/2);
	k=(k*k)%M;
	if(w%2==1) k=(k*a)%M;
	return k;
}

