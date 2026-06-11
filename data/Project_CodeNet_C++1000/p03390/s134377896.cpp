#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 100;
int T, A, B; ll pro;

bool check(ll k)
{
	ll a = k, b = k; bool fa = 0, fb = 0;
	if(k >= A) a++, fa = 1; if(k >= B) b++, fb = 1;
	ll c = a >> 1, d = b >> 1;
	if(k & 1)
	{
		if(c>=A || !fa) c++; if(d>=B || !fb) d++;
		return c*d < pro;
	}
	ll e = c + 1, f = d + 1;
	if(c >= A) c++, e++; if(d >= B) d++, f++;
	if(e == A) e++; if(f == B) f++;
	return c*f<pro && d*e<pro;
}

void Solve()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &A, &B);
		pro = 1ll * A * B;
		ll l = 0, r = 3ll * max(A, B);
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			if(check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		printf("%I64d\n", l-1);
	}
}

int main()
{
	Solve();
}