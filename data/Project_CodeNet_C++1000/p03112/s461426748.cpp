#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)x.size())

int main() {
    ll nax=1e5+7;
    int A,B,q;
    ll a[nax],b[nax];
		cin>>A>>B>>q;
		rep(i,0,A) cin>>a[i];
		rep(i,0,B) cin>>b[i];
		sort(a,a+A);
		sort(b,b+B);
		rep(i,0,q) {
			ll x,ans=1e17;
			cin>>x;
			int p1=lower_bound(a,a+A,x)-a;
			int p2=lower_bound(b,b+B,x)-b;
			if(p1>0&&p2>0) ans=min(ans,x-min(a[p1-1],b[p2-1]));
			if(p1<A&&p2<B) ans=min(ans,max(a[p1],b[p2])-x);
			if(p1>0&&p2<B) ans=min(ans,min(abs(x-a[p1-1]),abs(x-b[p2]))*2+max(abs(x-a[p1-1]),abs(x-b[p2])));
			if(p2>0&&p1<A) ans=min(ans,min(abs(x-a[p1]),abs(x-b[p2-1]))*2+max(abs(x-b[p2-1]),abs(x-a[p1])));
			cout<<ans<<'\n';
		}
		return 0;
}
