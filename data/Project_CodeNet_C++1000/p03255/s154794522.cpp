#include <bits/stdc++.h>
using namespace std;
//#define che
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MK make_pair
#define PB push_back
#define fi first
#define se second

typedef unsigned long long LL;
typedef pair<int, int> PII;
const int N=2e5 +10 ;

LL pre[N];int a[N], n, m, x;
int main(){
	#ifdef che
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	scanf("%d%d", &n, &x);
	for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
	reverse(a+1, a+n+1);
	pre[0] =0 ;
	for (int i=1; i<=n; ++i) pre[i] = pre[i-1] + 1ll*a[i];
	LL ans= -1; 
	for (int k=1 ; k<=n; ++k){
		LL res= 0 ;
		for (int i=1,j=0; j<n; j+=k, ++i)
			res += 1ll*(2*i+1+2*(i==1))*(pre[ min(j+k,n)] -pre[j]);
		
		res += 1ll*(n+k)*x;
		if (ans==-1) ans=res;
		ans= min(ans, res);
	}
	cout<<ans<<endl;
	return 0;
}