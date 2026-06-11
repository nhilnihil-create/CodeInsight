#include <bits/stdc++.h> 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ld double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define sz(x) ((long long)x.size())
#define all(x) (x).begin(), (x).end()
const int MOD =1e9+7;

int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1LL;}return res%p;}
const int N=2*1e5+2,M=20;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int b[n];
	for(int i=0;i<n;i++) cin>>b[i];
	int ans=0;
	for(int k=30;k>=0;k--)
	{
		int x=(1LL<<(k+1));
		for(int i=0;i<n;i++)
		{
			a[i]%=x;
		}
		for(int i=0;i<n;i++)
		{
			b[i]%=x;
		}
		sort(b,b+n);
		int cnt=0;
		int l=(1LL<<k);
		int r=(1LL<<(k+1));
		r--;
		for(int i=0;i<n;i++)
		{
			int ll=l-a[i];
			int rr=r-a[i];
			int count=(upper_bound(b,b+n,rr)-upper_bound(b,b+n,ll-1));
			cnt+=count;
		}
		l=(1LL<<k)+(1LL<<(k+1));
		r=(1LL<<(k+2));
		r--;
		for(int i=0;i<n;i++)
		{
			int ll=l-a[i];
			int rr=r-a[i];
			int count=(upper_bound(b,b+n,rr)-upper_bound(b,b+n,ll-1));
			cnt+=count;
		}
		if(cnt&1LL)
		{
			ans+=(1LL<<k);
		}
	}
	cout<<ans;
} 
// l<=a+b<=r
// l-a<=b<=r-a  
//          
// 2^k<=a+b<2^(k+1)
// 2^(k+1)+2^(k) <=a+b<2^(k+2)
