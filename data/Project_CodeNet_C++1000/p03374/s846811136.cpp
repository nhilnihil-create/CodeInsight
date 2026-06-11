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
#define MAXN 200007
#define mo 19930726
using namespace std;
typedef unsigned long long ull;
#define ms(arr) memset(arr, 0, sizeof(arr))
#define ll long long
const int inf = 0x3f3f3f3f;
ll n,v[MAXN],x[MAXN],C,sum[MAXN],pre[MAXN],ans;
int main()
{
	cin>>n>>C;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>v[i];
		sum[i]=sum[i-1]+v[i];
		pre[i]=max(pre[i-1],sum[i]-x[i]);
	}
	ll cnt=0;
	ll c=C;
	for(int i=n;i>=1;i--){
		ans=max(ans,cnt+pre[i]);
		cnt+=v[i]-2*(c-x[i]);
		c=x[i];
	}
	for(int i=1;i<=n;i++) x[i]=C-x[i];
	reverse(x+1,x+n+1);
	reverse(v+1,v+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+v[i];
		pre[i]=max(pre[i-1],sum[i]-x[i]);
	}
	cnt=0;
	c=C;
	for(int i=n;i>=1;i--){
		ans=max(ans,cnt+pre[i]);
		cnt+=v[i]-2*(c-x[i]);
		c=x[i];
	}
	cout<<ans;
}