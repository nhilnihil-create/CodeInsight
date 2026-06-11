#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
vector <int> c,d;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> a(n),b(n);
	for (int i=0;i<n;i++)a[i]=read();
	for (int i=0;i<n;i++)b[i]=read();
	ll ans=0,x=1;
	for (int k=0;k<=28;k++){
		c=a; d=b;
		 ll y=x*2;
		for (int i=0;i<n;i++){
			c[i]=c[i]%y;
			d[i]=d[i]%y;
		}
		sort(d.begin(),d.end());
		int m1=0;
		for (int i=0;i<n;i++){
			int l1,r1,l2,r2;
			l1=lower_bound(d.begin(),d.end(),x-c[i])-d.begin();
			r1=lower_bound(d.begin(),d.end(),2*x-c[i])-d.begin()-1;
			l2=lower_bound(d.begin(),d.end(),3*x-c[i])-d.begin();
			r2=lower_bound(d.begin(),d.end(),4*x-c[i])-d.begin()-1;
			m1+=(r1-l1+1+r2-l2+1);
		}
		if (m1&1) ans+=x;
		x*=2;
	}
	printf("%lld\n",ans);
	return 0;
}
