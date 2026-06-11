#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int l[N],r[N];
int main()
{	int n; ll ans=0; scanf("%d",&n);
	for(rint i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	sort(l,l+n+1); sort(r,r+n+1);
	for(rint i=0;i<=n;i++) ans+=max(0,l[n-i]-r[i]);
	cout<<2*ans;
	return 0;
}
