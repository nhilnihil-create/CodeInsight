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
int f(int a[],int n,int x)
{
	int b[n];
	ordered_set s;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=x) b[i]=1;
		else b[i]=-1;
	}
	for(int i=1;i<n;i++) b[i]+=b[i-1];
	s.insert({0,-1});
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=s.order_of_key({b[i]+1,-1e12});
		s.insert({b[i],i});
	}
	return cnt;
}
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int l=1,r=1e9;
	int m=n*(n-1)/2+n+1;
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int get=f(a,n,mid);
		if(get>=m/2)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}  