#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
#define ll long long
#define MAXN 100005
using namespace std;
typedef pair<int,int> pii;
template <typename T>
inline void read(T& a)
{
	T ret(0),f(1);char ch(getchar());
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){ret = ret * 10 + (ch ^ 48);ch = getchar();}
	a = ret * f;
}
inline int Max(int x,int y){return x > y ? x : y;}
inline int Min(int x,int y){return x < y ? x : y;}
inline ll gcd(ll x,ll y){return y ? gcd(y,x % y) : x;}
int main()
{
	int T;ll a,b,c,d,g;
	read(T);
	while(T--)
	{
		read(a),read(b),read(c),read(d);
		if(a < b || b > d) printf("No\n");
		else if(c > b - 2) printf("Yes\n");
		else
		{
			g = gcd(b,d);
			if((a - b) / g >= (a - c - 1) / g) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
