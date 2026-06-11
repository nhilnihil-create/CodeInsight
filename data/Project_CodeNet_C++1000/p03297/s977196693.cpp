#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<ctime>
#define up(i,x,y) for(int i = x;i <= y;i ++)
#define down(i,x,y) for(int i = x;i >= y;i --)
#define mem(a,b) memset((a),(b),sizeof(a))
#define mod(x) ((x)%MOD)
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
const int SIZE = 500010;
const int INF = 2147483640;
const double eps = 1e-8;

inline void RD(int &x)
{
    x = 0;  char c; c = getchar();
    bool flag = 0;
    if(c == '-')    flag = 1;
    while(c < '0' || c > '9')   {if(c == '-')   {flag = 1;} c = getchar();}
    while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0',c = getchar();
}
ll t;
ll a,b,c,d;
ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
bool pd(ll a,ll b,ll c,ll d)
{
	if(a < b)	return false;
	ll r = a/b+2;
	ll l = 0;
	ll mid;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if((a - mid*b) <= c)	r = mid - 1;
		else	l = mid + 1;
	}
	ll num = a - b * l;
	ll gc;
	gc = gcd(b,d);
	if(num < 0)	return false;
	if(b > d)	return false;
	if(c + gc < b)	return false;
	return true;
}

int main(int argc, char const *argv[])
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		if(pd(a,b,c,d))	cout<<"Yes"<<endl;
		else	cout<<"No"<<endl;
	}
	return 0;
}

/*
1
9 7 5 9

1
9 7 1 9
*/