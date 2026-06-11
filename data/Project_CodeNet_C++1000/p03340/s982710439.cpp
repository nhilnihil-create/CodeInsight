#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define ls ro<<1
#define fi first
#define se second
#define rs ro<<1|1
#define ll long long
#define int long long
#define pb push_back
#define vi vector<int>
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define lson ro<<1,l,mid
#define umap unordered_map
#define uset unordered_set
#define rson ro<<1|1,mid+1,r
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;
const int N=2e5+10;

int s[N],x[N],a[N];

signed main() {
	IOS;
#ifdef xiaofan
	freopen("in.txt","r",stdin);
#endif

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		x[i]=x[i-1]^a[i];
	}
	int l=1,r=1;
	int ans=0;
	while(r<=n){
		while((s[r]-s[l-1])!=(x[r]^x[l-1]))
			l++;
		//cout<<l<<" "<<r<<endl;
		ans+=r-l+1;
		r++;
	}
	cout<<ans<<endl;

#ifdef xiaofan
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
#endif
	return 0;
}

