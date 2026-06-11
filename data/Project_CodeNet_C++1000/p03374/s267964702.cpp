#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define de(x) cout<<#x<<"="<<x<<endl
	#define rff freopen("input.txt","r",stdin)
#else
	#define de(x)
	#define rff
#endif

#define PQ priority_queue
#define setp setprecision
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define el cout<<endl
#define ll long long
#define pb push_back
#define re return
#define se second
#define fi first
const int INF=(int)INFINITY;

ll n,c,x[100003],dr[100003],dl[100003],mxl[100003],mxr[100003];
ll ans;
ll now,tmp;
ll vr,vl;
int v[100003];

int main(){
	ios::sync_with_stdio(false);
//	rff;
	int p;
	cin>>n>>c;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>v[i];
	}
	for (int i=1;i<=n;i++){
		p=n-i+1;
		vr+=v[i];
		vl+=v[p];
		dr[i]=vr-x[i];
		dl[p]=vl-(c-x[p]);
		ans=max(max(dr[i],dl[p]),ans);
		mxr[i]=max(dr[i],mxr[i-1]);
		mxl[i]=max(dl[p],mxl[i-1]);
	}
	for (int i=1;i<=n;i++){
		p=n-i+1;
		ans=max(max(dr[i]-x[i]+mxl[n-i],dl[p]-(c-x[p])+mxr[n-i]),ans);
	}
	cout<<ans;
	re 0;
}