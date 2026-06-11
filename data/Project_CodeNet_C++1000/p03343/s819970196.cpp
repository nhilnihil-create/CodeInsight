#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define rep(i,st,ed) for (int i=st;i<=ed;++i)

const int INF=0x3f3f3f3f;
const int N=20005;

int a[N],b[N];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):v,ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

int main(void) {
	int n=read(),k=read(),q=read();
	rep(i,1,n) b[i]=a[i]=read();
	std:: sort(b+1,b+n+1);
	int ans=INF;
	rep(ti,1,n) {
		int mn=b[ti];
		std:: vector <int> v,r;
		v.push_back(0);
		rep(i,1,n) if (a[i]<mn) v.push_back(i);
		v.push_back(n+1);
		int pre=v[0];
		for (int i=1;i<v.size();++i) {
			int now=v[i];
			int len=now-pre-1;
			if (len<k) {pre=now; continue;}
			std::vector <int> s;
			rep(j,pre+1,now-1) s.push_back(a[j]);
			std:: sort(s.begin(),s.end());
			rep(j,0,len-k) r.push_back(s[j]);
			pre=now;
		}
		std:: sort(r.begin(),r.end());
		if (q<=r.size()) ans=std:: min(ans,r[q-1]-mn);
	}
	printf("%d\n", ans);
	return 0;
}