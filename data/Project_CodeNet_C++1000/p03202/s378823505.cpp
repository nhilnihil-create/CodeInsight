#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
const int N=2e5+10;
int n,a[N],l=1,r=N-10,mid,ans;
map<int,int>p;
inline bool judge(int x){
	p.clear();
	for(register int i=2;i<=n;i++){
		if(a[i]>a[i-1])continue;
		if(x==1)return 0;
		++p[a[i]];
		map<int,int>::iterator it=p.upper_bound(a[i]);
		while(it!=p.end())p.erase(it),it=p.upper_bound(a[i]);
		int pos=a[i];
		while(pos&&p[pos]==x)p[pos]=0,++p[--pos];
		if(!pos)return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(l<=r){mid=(l+r+1)>>1;if(judge(mid))ans=mid,r=mid-1;else l=mid+1;}
	printf("%d\n",ans);return 0;
}