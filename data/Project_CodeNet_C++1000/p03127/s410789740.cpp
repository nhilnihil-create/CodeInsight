#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define full(a) a.begin(),a.end()
#define stoink stack<ll>
#define vec vector <ll>
#define vg vector<vector<ll> >
#define vgw vector<vector<pair<ll,ll> >
#define pa pair<ll,ll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000000
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vec arr(n);
	ll i;
	ll ans;
	for ( i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	ans = arr[0];
	for(i = 1 ; i < n;i++) {
		ans = __gcd ( ans, arr[i]);
	}
	cout << ans << endl;
	return 0;
}