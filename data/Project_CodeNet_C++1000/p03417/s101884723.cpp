#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define sortv(a); sort(a.begin(), a.end());
#define rev(a); reverse(a.begin(), a.end());
#define FOR(i,a,b) for (ll i = (ll)(a); i < (b); i++)
#define ROF(i,a,b) for (ll i = (ll)(b)-1; i >= (a); i--)

ll MOD = 1000000007;
ll INF = 1LL << 60;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll n,m;cin>>n>>m;
	ll out;
	if (n==1 && m==1) {
		out=1;
	} else if (n==1) {
		out=max(0,(int)m-2);
	} else if (m==1) {
		out=max(0,(int)n-2);
	} else {
		out=(m-2)*(n-2);
	}

	cout<<out;
}