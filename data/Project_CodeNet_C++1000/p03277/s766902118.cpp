#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,a[N],s[N];
ll c[3*N];
int lowbit(int x){return x&(-x);}
void add(int x){
	for(;x<=2*N;x+=lowbit(x))c[x]++;
}
ll query(ll x){
	ll res=0;
	for(;x;x-=lowbit(x))res+=c[x];
	return res;
}
bool check(int x){
	ll res=0;
	memset(c,0,sizeof(c));
	s[0]=0;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+(a[i]>=x?1:-1);
	for(int i=0;i<=n;i++){
		res+=query(s[i]+N);
		add(s[i]+N);
	}
	if(res>=1LL*n*(n+1)/4)return 1;
	else return 0;
}
int main(){
	int l=0,r=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		r=max(r,a[i]);
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}