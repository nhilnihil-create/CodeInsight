// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+10, maxm=5e4+10, lg=21, mod=1e9+7, inf=1e18;

ll H,W,n,mn[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	memset(mn,69,sizeof(mn));
	cin>>H>>W>>n;
	while(n--){
		ll x,y; cin>>x>>y;
		mn[x]=min(mn[x],y);
	}
	for(int x=2,y=1;x<=H;x++){
		if(y>=mn[x]) return cout<<x-1,0;
		y+=(y+1<mn[x]);
	}
	cout<<H;
	
	return 0;
}



 
