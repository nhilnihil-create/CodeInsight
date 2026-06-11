#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;
 
#define MOD 1000000007
 
ll d[200010];
 
int main() {
	vector<pair<ll,ll> > v;
	clr(d,0);
	ll h,w,n;
	cin>>h>>w>>n;
  	swap(h,w);
	map<pair<ll,ll>,ll> ma;
	rep(i,0,n){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		v.pb(mp(x,y));
		ma[mp(x,y)]=1;
	}
	ll y = 0;
	ll x = 0;
	rep(i,1,w){
		if(ma[mp(x+1,y+1)]!=1){
			x++;
			y++;
		}
		else{
			x++;
		}
		d[i]=min(y,h-1);
	}
	ll mn = w-1;
	rep(i,0,v.sz){
		{
			ll x1 = v[i].fi-1;
			ll y1 = v[i].se;
			if(x1>=0){
				ll x2 = x1;
				ll y2 = y1;
				if(ma[mp(x2,y2)]!=1){
					if(y2<=d[x2]){
						mn = min(mn,x2);
					}
				}
			}
		}
	}
	cout << mn+1 << endl;
	return 0;
}