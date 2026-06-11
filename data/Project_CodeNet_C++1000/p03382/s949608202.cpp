#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define repd(i,j,k) for(int i=j;i>=k;--i)
#define pb push_back
#define mp make_pair
#define ll long long
IL int read(){int x;int _w=scanf("%d",&x);return x; }
IL void write(ll x){ printf("%lld\n",x); }
const int maxn=1e5+10;
int a[maxn];
int main() {
	int n=read();
	rep(i,1,n)a[i]=read();
	sort(a+1,a+1+n);
	int t=a[n],ans=0,p=0;
	rep(i,1,n-1)if(min(a[i],t-a[i])>ans)ans=min(a[i],t-a[i]),p=i;
	cout<<a[n]<<' '<<a[p]<<endl;
	return 0;
}
