#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1061109567
#define pb push_back
#define in(s) freopen(s,"r",stdin);
#define out(s) freopen(s,"w",stdout);
#define fi first
#define se second
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
#define fa(i,x) for (auto i:x)
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],a1[N],b1[N];
bool present(int k) {
	int x=(1<<k),tmp=2*x;
	fw (i,0,n) {
		a1[i]=a[i]%tmp;
		b1[i]=b[i]%tmp;
	}
	//fw (i,0,n) cout<<a1[i]<<" "<<b1[i]<<"\n";
	sort(a1,a1+n); sort(b1,b1+n);
	int cnt=0;
	fw (i,0,n) {
		int lst=lower_bound(b1,b1+n,2*x-a1[i])-b1-1,prev=lower_bound(b1,b1+n,x-a1[i])-b1;
		cnt+=(lst-prev+1);
		lst=lower_bound(b1,b1+n,4*x-a1[i])-b1-1,prev=lower_bound(b1,b1+n,3*x-a1[i])-b1;
		cnt+=(lst-prev+1);
	}
	//cout<<"cnt="<<cnt<<"\n";
	return cnt&1;
}
signed main() {
	//in("aome.inp");
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	fw (i,0,n) cin>>a[i];
	fw (i,0,n) cin>>b[i];
	/*
	For each of the 28 bits we are required to check if it will be on by the end of the sum.
	Consider 2 ^ k. MOD every element by 2 ^ (k + 1). Now, a[i] + b[j] will contain an 1 - bit at
	k if:
	2 ^ k <= a[i] + b[j] < 2 ^ (k + 1) (No bits at the 2 ^ (k + 1) position is received)
	Or 3 * 2 ^ k <= a[i] + b[j] < 4 * 2 ^ k (1 bit is found at 2 ^ (k + 1). Erasing it cause us
	to get to the above equation)
	Don't think I'm missing anymore conditions.
	*/
	int ans=0;
	fw (i,0,29) {
		if (present(i)) {
			//cout<<"Bit "<<i<<" is present\n";
			ans|=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}