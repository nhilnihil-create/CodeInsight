#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long
#define pq priority_queue
#define mp make_pair
#define pii pair<int,int>
#define mod 998244353

int lowbit(int x) {return x&(-x);}

int n;
struct node{
	int s,w,v;
}a[1010];

ll f[30010];

bool com(node a,node b) {
	return -a.w+b.w>-b.s+a.s;
} 

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i].w,&a[i].s,&a[i].v);
	sort(a+1,a+n+1,com);
	ll ans=0ll;
	for (int i=1;i<=n;i++)
		for (int j=a[i].s;j>=0;j--) {
			f[j+a[i].w]=max(f[j+a[i].w],f[j]+(ll)a[i].v);
			ans=max(ans,f[j+a[i].w]);
		}
	cout<<ans;
	return 0;
}