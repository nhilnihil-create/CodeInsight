#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0,g=0;
	cin>>n;
	vi v(n),sufx(n),pfx(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	for(int i=0;i<n;++i){
		g = __gcd(g,v[i]);
		pfx[i] = g;
	}
	g=0;
	for(int i=n-1;i>=0;--i){
		g = __gcd(g,v[i]);
		sufx[i]=g;
	}
	for(int i=0;i<n;++i){
		int now = 0;
		if(i>0) now = __gcd(now,pfx[i-1]);
		if(i+1 < n) now = __gcd(now,sufx[i+1]);
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}