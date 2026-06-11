#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n;
ll x,s[maxn],ans,sum;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(x);
	for (int i=1;i<=n;i++) {
		read(s[i]); s[i]+=s[i-1];
	}
	ans=1LL<<62;
	for (int i=1;i<=n;i++) {
		sum=x*i;
		for (int j=1,l=0,r=n;r&&sum<ans;j++,r=l-1) {
			l=max(r-i+1,1);
			if (j==1) sum+=5*(s[r]-s[l-1]);
			else sum+=(j*2+1)*(s[r]-s[l-1]);
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans+x*n);
	return 0;
}