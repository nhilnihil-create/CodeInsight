#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N=2010;
const int INF=1e9;
int n,m,q;
int a[N];
int d[N],dcnt;
inline int min(int x,int y){
	return x<y?x:y;
}
void readData(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
void Diz(){
	dcnt=n;
	for(int i=1;i<=n;i++) d[i]=a[i];
	sort(d+1,d+1+dcnt);
	dcnt=unique(d+1,d+1+dcnt)-d-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(d+1,d+1+dcnt,a[i])-d;
}
bool judge(int l,int r){ // [1,l)never [l,r]mustone
	int use=0;
	int cnt;
	for(int i=1,j=1;i<=n;i=j){
		if(a[i]<l){
			j=i+1;
			continue;
		}
		cnt=0;
		for(;j<=n&&a[j]>=l;j++)
			cnt+=(a[j]<=r);
		if((j-i)>=m)
			use+=min((j-i)-m+1,cnt);
	}
	return use>=q;
}
void solve(){
	int ans=INF;
	for(int i=1;i<=n;i++){
		int l=a[i],r=dcnt,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(judge(a[i],mid))
				r=mid-1;
			else 
				l=mid+1;
		}
		if(l<=dcnt)
			ans=min(ans,d[l]-d[a[i]]);
	}
	printf("%d\n",ans);
}
int main(){
	readData();
	Diz();
	solve();
	return 0;
}
