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

const ll maxn=1e5+10, maxm=5e4+10, lg=21, mod=1e9+7, inf=1e18;

ll n,L[maxn],R[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>L[i]>>R[i];
	sort(L,L+n,greater<ll>()), sort(R,R+n);
	ll sum=0,sub=0,mx=0;
	for(int i=0;i<n;i++){
		mx=max(mx,sum+=2*L[i]);
		mx=max(mx,sub-=2*R[i]);
		mx=max(mx,sum-=2*R[i]);
		mx=max(mx,sub+=2*L[i]);
	}
	cout<<mx;
	
	return 0;
}



 
