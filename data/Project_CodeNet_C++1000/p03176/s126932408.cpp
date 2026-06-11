#include<iostream>
#include<map>
#include<algorithm>
using namespace::std;
#define int long long int

int n,ar[200005],val[200005],bit[200005],srt[200005];
map<int,int> m;

int query(int x){
	int maxn=0;
	for(;x;x-=x&(-x))
		maxn=max(maxn,bit[x]);
	return maxn;
}

void upd(int x,int t){
	for(;x<=n;x+=x&(-x))
		bit[x]=max(bit[x],t);
}

main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>ar[i],srt[i]=ar[i];
	for(int i=1;i<=n;i++)
		cin>>val[i];
	sort(srt+1,srt+n+1);
	for(int i=1;i<=n;i++)
		m[srt[i]]=i;
	for(int i=1;i<=n;i++)
		upd(m[ar[i]],val[i]+query(m[ar[i]]));
	cout<<query(n)<<'\n';
}
