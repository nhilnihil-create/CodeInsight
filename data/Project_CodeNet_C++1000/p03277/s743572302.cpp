#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll a[maxn];
ll s[maxn * 10],c[maxn * 10];
ll n;
ll lowbit(ll x)
{
	return x & (-x);
}
ll query(ll x)
{
	ll sum = 0;
	for(;x;sum += c[x],x -= lowbit(x));
	return sum;
}
void update(ll x)
{
	for(;x <= maxn * 2;c[x]++,x += lowbit(x));
}
bool check(ll x)
{
	memset(c,0x00,sizeof(c));
	s[0] = 0;
	for(ll i = 1;i <= n; ++i)
	{
		s[i] = s[i - 1] + (a[i] >= x ? 1 : -1);
	}
	ll sum = 0;
	for(ll i = 0;i <= n; ++i)
	{
		sum += query(s[i] + maxn);
		update(s[i] + maxn);
	}
	return sum >= n * (n + 1) / 4;
}
int main()
{
	cin >> n;
	ll left = 0,right = 0;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
		right = max(right,a[i]);
	}
	right++;
	while(left+1<right){
		ll mid = (left+right)>>1;
		if(check(mid)) left = mid;
		else right = mid;
	}
	cout << left << endl;
}