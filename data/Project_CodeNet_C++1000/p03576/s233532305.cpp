#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 6000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n,k;
	cin>>n>>k;
	vector< pair<int,int> > a;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	sort( a.begin(), a.end() );
	ll ans = LINF;
	for(int i=0;i<=n-k;i++){
		for(int j=i+k-1;j<n;j++){
			int lx = a[j].first - a[i].first;
			vector<int> ys;
			for(int p=i;p<=j;p++){
				ys.pb( a[p].second );
			}
			sort( ys.begin(),ys.end() );
			int ly = LINF;
			for(int p=0;p<=ys.size()-k;p++){
				ly = min( ly, ys[p+k-1] - ys[p]);
			}
			ll tmp = lx * ly;
			if( ans > tmp ) ans = tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}