#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define re register
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 4000007
#define ll long long
#define mo 19930726
using namespace std;
typedef unsigned long long ull;
#define ms(arr) memset(arr, 0, sizeof(arr))
const int inf = 0x3f3f3f3f;
int n;
ll clac(ll x)
{
	ll cnt=0;
	while(x) cnt+=x%10,x/=10;
	return cnt;
}
int main()
{
	ll x=0,x1,x2,m=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		x1=x+m;x2=x+m*10;
		if(x1*clac(x2)<=x2*clac(x1))
			x=x1;
		else x=x2,m*=10;
		printf("%lld\n",x);
	}
}