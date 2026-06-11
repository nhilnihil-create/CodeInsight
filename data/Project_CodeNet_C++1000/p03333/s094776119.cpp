#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int l[100010],r[100010];
bool cmp(int a,int b){return a>b;}
int main(){
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",l+i,r+i);
	sort(l,l+n+1,cmp);
	sort(r,r+n+1);
	ans=0;
	for(i=0;i<=n;i++){
		if(l[i]<=r[i])break;
		ans+=l[i]-r[i];
	}
	printf("%lld",ans<<1);
}