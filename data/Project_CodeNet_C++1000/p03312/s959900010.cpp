#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define sortv(a); sort(a.begin(), a.end());
#define rev(a); reverse(a.begin(), a.end());
#define FOR(i,a,b) for (ll i = (ll)(a); i < (b); i++)
#define ROF(i,a,b) for (ll i = (ll)(b)-1; i >= (a); i--)
#define printarray(a) FOR(Q,0,(int)(a).size()) cout<<(a)[Q]<<" "; cout<<'\n';

ll MOD = 1000000007;
ll INF = 1LL << 60;

/*****************************************************************************/
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// freopen("input.txt", "r", stdin);
	int n;cin>>n;
	ll b[n];ll a[n];
	FOR(i,0,n)cin>>b[i];
	FOR(i,0,n)a[i]=b[i];
	FOR(i,1,n)a[i]+=a[i-1];
	int l=0;
	int r=2;
	ll out=INF,minn,maxx;
	FOR(i,1,n-2) {
		ll temp,l1,l2,r1,r2,cum;
		while(l<i) {
			l1=a[l];
			l2=a[i]-a[l];
			cum=abs(l1-l2);
			if (l+1==i) break;
			temp=abs(a[l+1]-(a[i]-a[l+1]));
			if (temp<cum) {
				l++;
			} else {
				break;
			}
		}
		while(r<n-1) {
			r1=a[r]-a[i];
			r2=a[n-1]-a[r];
			cum=abs(r1-r2);
			if (r+1==n-1) break;
			temp=abs(a[r+1]-a[i]-(a[n-1]-a[r+1]));
			if (temp<cum) {
				r++;
			} else {
				break;
			}
		}
		minn=min(min(min(r1, r2),l1),l2);
		maxx=max(max(max(r1, r2),l1),l2);
		// cout<<i<<" "<<l<<" "<<r<<" "<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<" "<<minn<<" "<<maxx<<'\n';
		out=min(out,abs(maxx-minn));
	}

	if (n==4) {
		minn=*min_element(b,b+4);
		maxx=*max_element(b,b+4);
		out=min(out,abs(maxx-minn));
	}
	cout<<out;
}