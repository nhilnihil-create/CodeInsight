#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int b,c;
}a[100005];
int cmp(node x,node y){
	return x.c>y.c;
}
int d[100005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&d[i]);
	sort(d,d+n);
	for(int i=0;i<m;i++)
		scanf("%d%d",&a[i].b,&a[i].c);
	sort(a,a+m,cmp);
	int id=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(d[i]<a[id].c&&a[id].b){
			ans+=a[id].c;
			a[id].b--;
		}
		else ans+=d[i];
		if(a[id].b==0){
			if(id+1<m)
				id++;
		}
	}
	printf("%lld\n",ans);
}