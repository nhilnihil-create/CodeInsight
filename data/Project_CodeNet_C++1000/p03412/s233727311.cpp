#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N],v[N],bin[31],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	bin[0]=1;
	for(int i=1;i<=30;i++) bin[i]=bin[i-1]<<1;
	sort(b+1,b+n+1);
	for(int i=0;i<=29;i++){
		int now=0;
		for(int j=1;j<=n;j++){
			v[j]=b[j]&((1<<i+1)-1);
			//cout<<v[j]<<' ';
		}
		//cout<<endl;
		sort(v+1,v+n+1);
		for(int j=1;j<=n;j++){
			int x=a[j]&((1<<i+1)-1);
			int y1=max(bin[i]-x,0),y2=(bin[i+1]-x-1),p1=0,p2=0;
			p1=lower_bound(v+1,v+n+1,y1)-v;
			p2=upper_bound(v+1,v+n+1,y2)-v-1;
			now+=(p2-p1+1);
			int y3=(bin[i+1]+bin[i]-x),y4=bin[i+2],p3=0,p4=n;
			p3=lower_bound(v+1,v+n+1,y3)-v;
			now+=(p4-p3+1);
			//cout<<p1<<' '<<p2<<' '<<y1<<' '<<y2<<"  "<<p3<<' '<<p4<<' '<<y3<<' '<<y4<<endl;
		}
		//cout<<i<<' '<<now<<endl;
		if(now&1) ans+=(1<<i);
	}
	printf("%d\n",ans);
	return 0;
}
