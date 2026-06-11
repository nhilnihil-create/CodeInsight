#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],b[200005];
int c[200005],d[200005];
bool f[35];
int n,ans;
signed main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<=30;i++){
		int t=(1<<i);
		for(int j=0;j<n;j++)
			c[j]=a[j]%(2*t),d[j]=b[j]%(2*t);
		sort(d,d+n);
		for(int j=0;j<n;j++){
			int y=2*t-c[j];
			int x=t-c[j];
			int p1=lower_bound(d,d+n,x)-d;
			int p2=lower_bound(d,d+n,y)-d;
			if(d[p2]>=y)p2--;
			if(p2>=n)p2--;
			if(p2>=p1&&(p2-p1+1)%2==1)f[i]=!f[i];
			y=4*t-c[j];
			x=3*t-c[j];
			p1=lower_bound(d,d+n,x)-d;
			p2=lower_bound(d,d+n,y)-d;
			if(d[p2]>=y)p2--;
			if(p2>=n)p2--;
			if(p2>=p1&&(p2-p1+1)%2==1)f[i]=!f[i];
		}
	}
	for(int i=0;i<=30;i++)
		if(f[i])ans|=(1<<i);
	cout<<ans<<endl;
	return 0;
}
